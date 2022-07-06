#include <iostream>
#include <array>
#include <vector>

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    for (int el : arr1)
    {
        std::cout << el << "\t";
    }
    std::cout << std::endl;

    for (int v : vec)
    {
        std::cout << v << "\t";
    }
    std::cout << std::endl;

    for (int el : arr)
    {
        std::cout << el << "\t";
    }
    std::cout << std::endl;

    return 0;
}
