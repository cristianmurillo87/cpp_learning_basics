#include <iostream>
#include <stack>

int main()
{
    /**
     * stacks are last-in first-out containers
    */
    std::stack<std::string> custs;
    custs.push("George");
    custs.push("Louise");
    custs.push("Florence");

    std::cout << "Size " << custs.size() << std::endl;
    if (!custs.empty())
    {
        for (int i = 0; i < custs.size(); i++)
        {
            std::cout << custs.top() << std::endl;
            custs.pop();
        }
    }
    return 0;
}