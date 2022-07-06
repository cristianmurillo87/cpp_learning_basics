#include <iostream>
#include <deque>
/**
 * Double ended deques are data structures that can 
 * be expanded or contracted from both sides
 * (start or end)
 */

int main()
{
    std::deque<int> nums{1, 2, 3, 4};
    // add to the front
    nums.push_front(0);
    // add to the back
    nums.push_back(5);
    for (int num : nums)
    {
        std::cout << num << "\t";
    }
    std::cout << std::endl;

    return 0;
}