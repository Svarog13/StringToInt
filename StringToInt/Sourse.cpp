#include<iostream>
#include <string>

int ConvertStringToInt(const std::string& str)
{
    try
    {
        size_t pos;
        int result = std::stoi(str, &pos);

        if (pos != str.length())
        {
            throw std::invalid_argument("Incorrect number format");
        }

        return result;
    }
    catch (const std::out_of_range&)
    {
        throw std::out_of_range("The number exceeds the range of int");
    }
    catch (const std::exception&)
    {
        throw std::invalid_argument("Incorrect number format");
    }
}


int main()
{
    std::string input;
    std::cout << "Enter the digit: ";
    std::cin >> input;

    try
    {
        int result = ConvertStringToInt(input);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}