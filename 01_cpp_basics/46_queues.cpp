#include <iostream>
#include <queue>

int main()
{
    /**
     * queues are first-in first-out containers
    */
    std::queue<std::string> custs;
    custs.push("George");
    custs.push("Louise");
    custs.push("Florence");

    std::cout << "Size " << custs.size() << std::endl;
    if (!custs.empty())
    {
        for (int i = 0; i < custs.size(); i++)
        {
            std::cout << custs.front() << std::endl;
            custs.pop();
        }
    }
    return 0;
}