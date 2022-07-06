#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums{1, 2, 3, 4};
    std::vector<int>::iterator itr;

    for (itr = nums.begin(); itr < nums.end(); itr++)
    {
        std::cout << *itr << "\t";
    }

    std::cout << std::endl;

    // start the iterator at a specific index
    std::vector<int>::iterator itr2 = nums.begin();
    // move it two positions forward
    std::advance(itr2, 2);
    std::cout << *itr2 << std::endl;

    // next position
    auto itr3 = next(itr2, 1);
    std::cout << *itr3 << std::endl;

    // previous position
    auto itr4 = prev(itr2, 1);
    std::cout << *itr4 << std::endl;

    return 0;
}