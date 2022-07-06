#include <iostream>
#include <vector>

// the const prevents the function from changing the value of the  passed argument
void print_array(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main()
{
    int data[] = {1, 2, 3};
    print_array(data, 3);
    return 0;
}