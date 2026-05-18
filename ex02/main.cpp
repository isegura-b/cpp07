#include <iostream>
#include <string>

#include "Array.hpp"

template <typename T>
void printArray(const Array<T> &array, const std::string &label)
{
    std::cout << label << " [size=" << array.size() << "]: ";
    for (std::size_t i = 0; i < array.size(); ++i)
        std::cout << array[i] << (i + 1 == array.size() ? "" : " ");
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== Empty constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << "\n=== Size constructor ===" << std::endl;
    Array<int> numbers(5);
    for (std::size_t i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>((i + 1) * 10);
    printArray(numbers, "numbers");

    std::cout << "\n=== Copy constructor / deep copy ===" << std::endl;
    Array<int> copy(numbers);
    copy[0] = 999;
    printArray(numbers, "original");
    printArray(copy, "copy");

    std::cout << "\n=== Assignment operator / deep copy ===" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    assigned[1] = 777;
    printArray(numbers, "original");
    printArray(assigned, "assigned");

    std::cout << "\n=== Const access ===" << std::endl;
    const Array<int> constNumbers(numbers);
    std::cout << "constNumbers[2] = " << constNumbers[2] << std::endl;

    std::cout << "\n=== Different type ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "from";
    words[2] = "Array<T>";
    printArray(words, "words");

    std::cout << "\n=== Out of bounds exception ===" << std::endl;
    try
    {
        std::cout << numbers[numbers.size()] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}