#include <iostream>
#include <memory>
#include <stdio.h>

/* malloc sets aside an amount of continuous memory space defined by the user 
*  and returns a pointer to that memory address
*/
int main()
{
    int amount_to_store;

    std::cout << "How many numbers do you want to store?: ";
    std::cin >> amount_to_store;

    int *p_nums;
    /* set how much space to set aside using malloc 
     * and the returned value a pointer
     * since malloc returns a pointer of type void
     * it is necessary to cast it to the desired data type
    */
    p_nums = (int *)malloc(amount_to_store * sizeof(int));

    // depending on the library implementation
    // malloc could return a null pointer if the value passed to malloc is zero
    // so, make sure it's not
    if (p_nums != NULL)
    {
        int i = 0;
        while (i < amount_to_store)
        {
            std::cout << "Enter a number: ";
            std::cin >> p_nums[i];
            i++;
        }
    }

    std::cout << "Numbers entered: ";
    for (int i = 0; i < amount_to_store; i++)
    {
        std::cout << p_nums[i] << "\t";
    }
    std::cout << std::endl;

    delete p_nums;

    return 0;
}