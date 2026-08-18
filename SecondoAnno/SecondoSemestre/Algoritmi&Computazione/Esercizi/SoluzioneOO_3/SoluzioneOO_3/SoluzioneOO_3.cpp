#include <iostream>
#include <string>
#include <sstream>

#include "StackOfInt.h"
#include "Stack.h"

int main()
{
    // Using basic stack of integers
    StackOfInt myStack;
    for (int i = 0; i < 10; ++i)
    {
        myStack.push(i);
    }
    StackOfIntIterator *itr = myStack.getIterator();
    std::cout << "Displaying stack contents: " << std::endl;
    while (itr->hasNext())
    {
        std::cout << itr->current() << std::endl;
        itr->next();
    }

    // Now making a stack of strings
    Stack<std::string> stackOfStrings;
    for (int i = 0; i < 10; ++i)
    {
        std::ostringstream temp;
        temp << "Counter: " << i;
        stackOfStrings.push(temp.str());
    }
    auto sitr = stackOfStrings.getIterator();
    while (sitr->hasNext())
    {
        std::cout << sitr->current() << std::endl;
        sitr->next();
    }

    return 0;
}
