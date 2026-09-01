/** @file
 * @brief Solution of pretty-printing exercise
 */

/** @mainpage Works
 * The purpose of this project is to showcase polymorfysm
 *
 * This program reads lines of text from a CSV file and parses them
 * into object of the right kind, then pretty-prints the objects.
 * Creation and printing of the objects should not change much
 * when new classes are added.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string_view>
#include <vector>

/** @brief Defines a default constant for the CSV separator
 */
static constexpr char DEFAULT_SEPARATOR{';'};

/** @brief Splits a string using a delimiter
 *
 * Splits the string @p text in one or more string fields using the separator @p separator.
 * @param text the string to be splitted
 * @param separator the characted used to split the string
 * @return a vector of strings corresponding to the fields
 */
std::vector<std::string> split(std::string text, char separator = DEFAULT_SEPARATOR)
{
    size_t begin = 0;
    std::vector<std::string> fields;
    while (begin < text.size())
    {
        size_t sep_idx = text.find(separator, begin);
        if (sep_idx == std::string::npos)
        {
            fields.push_back(text.substr(begin, (text.size() - begin)));
            begin = text.size();
        }
        else
        {
            fields.push_back(text.substr(begin, (sep_idx - begin)));
            begin = sep_idx + 1;
        }
    }
    return fields;
}

/** @brief Utility function to convert a string to an int
 *
 * Puts the string @p s into a string stream and attempts to read an integer.
 * @param s the string to be converted
 * @return an integer corresponding to the value read from the string
 */
int string_to_int(std::string_view s)
{
    std::stringstream tmp_string{s.data()};
    int tmp{0};
    tmp_string >> tmp;
    return tmp;
}

class work
{
public:
    static const size_t tag_pos = 0;
    static const size_t id_pos = 1;
    static const size_t title_pos = 2;

    work() = default;
    work(work const &w) = default;
    work(std::string_view id, std::string_view title) : id_{id}, title_{title} {}
    virtual ~work() {}
    std::string const &id() const { return id_; }
    std::string const &title() const { return title_; }
    virtual void print(std::ostream &) const = 0;
    virtual void parse(std::string, char separator = DEFAULT_SEPARATOR) = 0;

protected:
    void set(std::string_view id, std::string_view title)
    {
        id_ = id;
        title_ = title;
    }

private:
    std::string id_;
    std::string title_;
};

/** @brief Overloading the operator for output streams for work objects
 */
std::ostream &operator<<(std::ostream &out, work const &w)
{
    w.print(out);
    return out;
}

class book : public work
{
public:
    static const size_t author_pos = 3;
    static const size_t pubyear_pos = 4;

    book() : work{}, author_{}, pubyear_{} {}
    book(book const &b) = default;
    book(std::string_view id, std::string_view title,
         std::string_view author, int pubyear)
        : work{id, title}, author_{author}, pubyear_{pubyear} {}
    std::string const &author() const { return author_; }
    int pubyear() const { return pubyear_; }
    void print(std::ostream &out) const override
    {
        out << author() << ", " << title() << ", " << pubyear() << '.';
    }
    void parse(std::string line, char separator = DEFAULT_SEPARATOR) override
    {
        std::vector<std::string> fields = split(line);
        set(fields[work::id_pos], fields[work::title_pos]);
        author_ = fields[book::author_pos];
        pubyear_ = string_to_int(fields[book::pubyear_pos]);
    }

private:
    std::string author_;
    int pubyear_;
};

class periodical : public work
{
public:
    static const size_t volume_pos = 3;
    static const size_t number_pos = 4;
    static const size_t date_pos = 5;

    periodical() : work{}, volume_{0}, number_{0}, date_{} {}
    periodical(periodical const &p) = default;
    periodical(std::string_view id, std::string_view title,
               int volume, int number, std::string_view date)
        : work{id, title}, volume_{volume}, number_{number},
          date_{date} {}
    int volume() const { return volume_; }
    int number() const { return number_; }
    std::string const &date() const { return date_; }
    void print(std::ostream &out) const override
    {
        out << title() << ", "
            << volume() << '('
            << number() << "), " << date() << '.';
    }
    void parse(std::string line, char separator = DEFAULT_SEPARATOR) override
    {
        std::vector<std::string> fields = split(line);
        set(fields[work::id_pos], fields[work::title_pos]);
        volume_ = string_to_int(fields[periodical::volume_pos]);
        number_ = string_to_int(fields[periodical::number_pos]);
        date_ = fields[periodical::date_pos];
    }

private:
    int volume_;
    int number_;
    std::string date_;
};

class movie : public work
{
public:
    static const size_t runtime_pos = 3;

    movie() : work{}, runtime_{0} {}
    movie(movie const &) = default;
    movie(std::string_view id, std::string_view title, int runtime) : work{id, title}, runtime_{runtime} {}

    int runtime() const { return runtime_; }
    void print(std::ostream &out) const override
    {
        out << title() << " (" << runtime() << " min)";
    }
    void parse(std::string line, char separator = DEFAULT_SEPARATOR) override
    {
        std::vector<std::string> fields = split(line);
        set(fields[work::id_pos], fields[work::title_pos]);
        runtime_ = string_to_int(fields[movie::runtime_pos]);
    }

private:
    int runtime_; ///< running length in minutes
};

class report : public work
{
public:
    static const size_t institute_pos = 3;

    report() : work{} {}
    report(report const &) = default;
    report(std::string_view id, std::string_view title, std::string_view institution) : work{id, title}, institution_{institution} {}

    std::string const &institution() const { return institution_; }
    void print(std::ostream &out) const override
    {
        out << title() << " (from " << institution() << ", all rights reserved)";
    }
    void parse(std::string line, char separator = DEFAULT_SEPARATOR) override
    {
        std::vector<std::string> fields = split(line);
        set(fields[work::id_pos], fields[work::title_pos]);
        institution_ = fields[report::institute_pos];
    }

private:
    std::string institution_;
};

/** @brief Factory function for work objects
 * This function generates the right kind of object using default constructors
 *
 * @param line the file line from which a tag can be extracted to decide which object to create
 * @param separator the field separator
 */
work *make_work(std::string line, char separator = DEFAULT_SEPARATOR)
{
    std::string tag = line.substr(0, line.find(separator));
    if (tag == "book")
        return new book{};
    else if (tag == "periodical")
        return new periodical{};
    else if (tag == "movie")
        return new movie{};
    // L'unica modifica (oltre alla definizione di report)
    else if (tag == "report")
        return new report{};
    else
        return nullptr;
}

/** @brief reads entries from a file.
 *
 * All the entries in a file are parsed and returned as a vector of pointers to objects
 * @param file_name the name of the file to be parsed
 * @param separator the field separator
 * @return a vector of pointer to newly created object specific for each entry
 */
std::vector<work *> read_entries(std::string file_name, char separator = DEFAULT_SEPARATOR)
{
    std::vector<work *> entries;
    std::ifstream in_file{file_name};
    if (!in_file.is_open())
    {
        perror("Error while opening file");
    }
    std::string line;
    while (std::getline(in_file, line))
    {
        // Generate a default object and then parse contents into it
        work *w = make_work(line, separator);
        if (w != nullptr)
        {
            w->parse(line, separator);
        }
        entries.push_back(w);
    }
    if (in_file.bad())
    {
        perror("error while reading file");
    }
    in_file.close();
    return entries;
}

/** @brief Function to pretty print a set of entries (relying on class methods)
 * Scans the @p entries vector and prints each element in the @p out stream.
 * It assumes that each element of the vector is a ponter to an object of class work.
 * @param out the output stream
 * @entries a vector of entries (subclasses of work)
 */
void print_pretty(std::ostream &out, std::vector<work *> const &entries)
{
    for (auto entry : entries)
    {
        if (entry != nullptr)
        {
            out << *entry << std::endl
                << std::endl;
        }
    }
    /*
    // Definizione alternatativa con iteratori
    for (std::vector<work*>::const_iterator entry_itr = entries.begin();
        entry_itr != entries.end(); ++entry_itr) {
        if (*entry_itr != nullptr) {
            auto entry = *entry_itr;
            out << *entry << std::endl << std::endl;
        }
    }
    // Definizione alternativa con indice numerico
    for (int i = 0; i < entries.size(); ++i) {
        if (entries[i] != nullptr) {
            out << entries[i] << std::endl << std::endl;
        }
    }
    */
}

/** @brief Main program.
 * Asks the user about a file to parse, then reads the entries in a vector and prints them.
 */
int main()
{
    std::string file_name;
    std::cout << "Please enter the file to be processed: ";
    std::cin >> file_name;

    std::vector<work *> entries = read_entries(file_name);
    print_pretty(std::cout, entries);

    return 0;
}
