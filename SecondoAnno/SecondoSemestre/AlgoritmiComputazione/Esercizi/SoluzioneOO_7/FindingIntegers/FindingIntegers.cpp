#include "data.h"

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

