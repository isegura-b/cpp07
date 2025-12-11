#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"


#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "=== Empty constructor ===" << std::endl;
    Array<int> a;
    std::cout << "size: " << a.size() << std::endl;

    std::cout << "\n=== Size constructor ===" << std::endl;
    Array<int> b(5);
    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = i * 10;

    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> c(b);
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Modify copy (deep copy test) ===" << std::endl;
    c[0] = 999;

    std::cout << "b[0]: " << b[0] << " (should still be 0)" << std::endl;
    std::cout << "c[0]: " << c[0] << " (should be 999)" << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> d;
    d = b;
    d[1] = 777;

    std::cout << "b[1]: " << b[1] << " (should not change)" << std::endl;
    std::cout << "d[1]: " << d[1] << " (should be 777)" << std::endl;

    std::cout << "\n=== Out-of-bounds index exception ===" << std::endl;
    try
    {
        std::cout << b[100] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}


/*
#define MAX_VAL 750
int main(int, char **)
{
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return 0;
}*/