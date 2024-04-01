#include <iostream>
int main()
{
    for (int i = 1; i < 101; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "CracklePop" << std::endl;
        else if (i % 3 == 0)
            std::cout << "Crackle" << std::endl;
        else if (i % 5 == 0)
            std::cout << "Pop" << std::endl;
        else
            std::cout << i << std::endl;
    }
}