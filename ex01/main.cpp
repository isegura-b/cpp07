#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &v)
{
    std::cout << v << std::endl;
}

void plus(int &x)
{
    x = x + 1;
}

void upper(std::string &s)
{
    for (std::size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = static_cast<char>(s[i] - 'a' + 'A');
    }
}

int main()
{
    int inter[] = {1, 2, 3};
    const std::size_t ni = sizeof(inter) / sizeof(inter[0]); //int * 3 = 12 bytes / sizeof(int) == 4 bytes ====> 3 elements
    iter(inter, ni, print<int>);
    std::cout << "[+ 1]" << std::endl;
    iter(inter, ni, plus);
    iter(inter, ni, print<int>);

    std::string str[] = {"hola", "mundo"};
    const std::size_t ns = sizeof(str) / sizeof(str[0]);    //std::string * 2 = 16 bytes / sizeof(std::string) == 8 bytes ====> 2 elements
    iter(str, ns, upper);
    iter(str, ns, print<std::string>);

    return 0;
}
