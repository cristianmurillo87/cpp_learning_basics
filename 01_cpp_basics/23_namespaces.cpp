#include <iostream>
#include <vector>

namespace utilz
{
    void print_array(int array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int guesses[] = {10, 13, 54, 62, 12, 12, 13};
    std::cout << guesses[3] << std::endl;
    guesses[3] = 101;
    std::cout << guesses[3] << std::endl;
    int size = sizeof(guesses) / sizeof(guesses[0]);
    utilz::print_array(guesses, size);

    int fixed_size_array[10];
    std::cout << fixed_size_array[3] << std::endl;
    std::cout << sizeof(fixed_size_array) / sizeof(fixed_size_array[3]) << std::endl;
    int size_of_fixed = sizeof(fixed_size_array) / sizeof(fixed_size_array[0]);
    utilz::print_array(fixed_size_array, size_of_fixed);

    return 0;
}