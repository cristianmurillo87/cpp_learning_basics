/**
 * Forward list are like lists, but an item only has access
 * to the next element in the list an not to the preceding one
*/
#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> fl1;
    fl1.assign({1, 2, 3, 4});

    fl1.push_front(0);
    fl1.pop_front();

    std::cout << "Front: " << fl1.front() << std::endl;

    std::forward_list<int>::iterator it4 = fl1.begin();
    it4 = fl1.insert_after(it4, 5);
    fl1.emplace_front(6);
    fl1.remove(6);

    return 0;
}