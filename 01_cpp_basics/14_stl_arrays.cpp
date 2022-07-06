#include <iostream>
#include <array>

// stl arrays always know their size
void print_array(std::array<int, 20> arr)
{
    // prints all elements, event those that are not yet assigned
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

// stl arrays are by default passed by value
// use references to modify the values in place inside a function
void append_to_array(std::array<int, 20> &arr, int new_element)
{
    arr[arr.size() - 1] = new_element;
}

int main()
{
    // stl arrays are statically typed and the data type
    // the size must be given must be given when declared
    std::array<int, 20> data = {1, 2, 3};
    print_array(data);
    append_to_array(data, 4);
    print_array(data);
    return 0;
}