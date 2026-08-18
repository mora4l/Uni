#include <iostream>
#include <string>
#include <vector>
#include <fstream>

static constexpr char DEFAULT_SEP = ';';

class work {
public:
    // TODO: define class
    virtual void parse(std::string const& s) = 0;
};

class book : public work {
public:
    // TODO: define class
    void parse(std::string const& s) override {}
};

class periodical : public work {
public:
    // TODO: define class
    void parse(std::string const& s) override {}
};

class movie : public work {
public:
    // TODO: define class
    void parse(std::string const& s) override {}
};

work* make_work(std::string const& buffer, char separator = DEFAULT_SEP) {
    // Extract the tag and create an object based on the value of the tag
    std::string tag = buffer.substr(0, buffer.find(separator));
    if (tag == "book") {
        return new book{};
    } else if (tag == "periodical") {
        return new periodical{};
    } else if (tag == "movie") {
        return new movie{};
    }
    return nullptr;
}

std::vector<work*> read_entries(std::string const& file_name) {
    std::vector<work*> result;
    std::ifstream in_file{ file_name };

    // Check if the file is there
    if (!in_file.is_open()) {
        perror("Error while opening file");
    }

    // Read the file line by line and create objects
    std::string buffer;
    while (std::getline(in_file, buffer)) {
        // Debug: std::cout << buffer << std::endl;
        // Call factory method make work to create an object of the right kind
        // based on the data tag (book, periodical, ...)
        work* w = make_work(buffer);
        if (w != nullptr) {
            // Assume that a parse function exists for objects of class work
            w->parse(buffer);
        }
        // Add the object to the resulting list
        result.push_back(w);
    }
    return result;
}

void print_pretty(std::ostream& out, std::vector<work*> const& entries) {
    // Scan the vector and print each entry
    for (auto entry : entries) {
        out << entry;
    }
}

int main()
{
    // Ask the user for a file name
    std::string file_name;
    std::cout << "Please enter the name of the file to be processed: ";
    std::cin >> file_name;

    // Read all the entries in the file in a vector
    std::vector<work*> entries = read_entries(file_name);
    print_pretty(std::cout, entries);

    return 0;
}

