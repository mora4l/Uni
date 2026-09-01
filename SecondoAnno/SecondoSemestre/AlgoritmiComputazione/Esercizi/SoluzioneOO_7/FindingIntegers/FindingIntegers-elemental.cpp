#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

/// Convenient shorthand for a vector of integers.
using intvector = std::vector<int>;

/// Read a series of integers from an input stream into @p data,
/// overwriting @p data in the process.
/// @param[in,out] data a vector of integers
/// @param[in] an input stream
void read_data(intvector& data, std::istream& in) {
    data.clear();
    data.insert(data.begin(), std::istream_iterator<int>(in),
        std::istream_iterator<int>());
}

/// Write a vector of integers to an output stream. Write all values on one
/// line, separated by single space characters, and surrounded by curly braces,
/// e.g., { 1 2 3 }.
/// @param data a vector of integers
void write_data(intvector const& data, std::ostream& out) {
    std::cout << "{ ";
    std::ranges::copy(data, std::ostream_iterator<int>(out, " "));
    std::cout << "}\n";
}

int main() {
    intvector data{};

    read_data(data, std::cin);
    write_data(data, std::cout);

    if (auto iter{ std::ranges::find(data, 42) }; iter == data.end())
        std::cout << "Value 42 not found\n";
    else {
        *iter = 0;
        std::cout << "Value 42 changed to 0:\n";
        write_data(data);
    }
}


