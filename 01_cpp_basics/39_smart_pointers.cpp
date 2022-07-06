#include <iostream>
#include <memory>
#include <stdio.h>

int main()
{
    int amount_to_store;

    std::cout << "How many numbers do you want to store?: ";
    std::cin >> amount_to_store;
    std::unique_ptr<int[]> pNums(new int[amount_to_store]);

    if (pNums != NULL)
    {
        int i = 0;
        while (i < amount_to_store)
        {
            std::cout << "Enter a number: ";
            std::cin >> pNums[i];
            i++;
        }
    }

    std::cout << "You entered these numbers: " << std::endl;
    for (int i = 0; i < amount_to_store; i++)
    {
        std::cout << pNums[i] << "\t";
    }

    std::cout << std::endl;

    return 0;
}
