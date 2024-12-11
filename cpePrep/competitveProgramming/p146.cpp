#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string code;

    // Read input line by line
    while(std::getline(std::cin, code))
    {
        // Check for the termination line
        if(code == "#")
            break;

        // Try to generate the next permutation
        if(std::next_permutation(code.begin(), code.end())) 
        {
            std::cout << code << std::endl;
        }
        else
        {
            std::cout << "No successor" << std::endl;
        }
    }

    return 0;
}