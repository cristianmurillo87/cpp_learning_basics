#include <iostream>
#include <vector>

int main()
{
    // at least the size of the inner array must be declared
    int grades[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << grades[row][col] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> vec_grades = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << vec_grades[row][col] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}