/**
 * Lists are very efficient at inserting, moving and extracting elements
 * but lack of direct access to those elements.
 * 
 * Lists cannot be accessed by using indexes:
 *  e.g my_list[0] would throw an error
*/
#include <iostream>
#include <deque>
#include <list>

int main()
{
    int arr[5]{1, 2, 3, 4, 5};
    std::list<int> list1;

    list1.insert(list1.begin(), arr, arr + 5);

    // assign replaces the content of the list
    list1.assign({10, 11, 12});

    list1.push_back(5);
    list1.push_front(1);

    std::cout << list1.size() << std::endl;

    std::list<int>::iterator it2 = list1.begin();
    advance(it2, 1);
    std::cout << "2nd Index " << *it2 << std::endl;

    it2 = list1.begin();
    list1.insert(it2, 8);

    list1.erase(list1.begin());

    it2 = list1.begin();
    std::list<int>::iterator it3 = list1.begin();
    advance(it3, 2);

    list1.erase(it2, it3);

    int arr2[6]{10, 9, 8, 7, 6, 6};
    std::list<int> list2;
    list2.insert(list2.begin(), arr2, arr2 + 5);

    list2.sort();
    list2.reverse();
    list2.unique();
    list2.remove(6);
    list1.merge(list2);

    for (int i : list1)
        std::cout << i << "\t";

    std::cout << std::endl;

    return 0;
}
