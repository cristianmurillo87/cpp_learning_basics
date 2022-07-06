#include <iostream>
#include <time.h>

int main()
{
    // seed the generation of random numbers
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        // Generate random numbers between 1 and 10
        std::cout << rand() % 10 + 1 << std::endl;
    }

    for (int j = 0; j < 10; j++)
    {
        // Generate random numbers between 0 and 1
        std::cout << (double)rand() / RAND_MAX << std::endl;
    }

    return 0;
}