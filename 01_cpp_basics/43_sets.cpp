#include <iostream>
#include <set>

int main()
{
    /**
     * A set is a container for unique and ordered elements.
     * Elements in a set cannot be accessed through indexes,
     * instead of them, iterators can be used.
     * 
     * Another type of container are multisets, which are similar to sets
     * with the only difference being that these can store duplicate numbers
     * and the elements are organized in ascending order
    */
    std::set<int> set1{5, 4, 3, 2, 1, 1};
    std::cout << "Size of the set: " << set1.size() << std::endl;

    // inserting a new element
    set1.insert(0);

    // sequential access using iterators
    std::set<int>::iterator it = set1.begin();
    it++;
    std::cout << "2nd value: " << *it << std::endl;

    set1.erase(5);
    it = set1.end();

    // move the iterator two spaces backwards
    advance(it, -2);
    // delete elements from the location of the iterator to the end of the set

    int arr[] = {6, 7, 8, 9};
    set1.insert(arr, arr + 4);

    auto val = set1.find(6);
    std::cout << "Found " << *val << std::endl;

    auto eight = set1.lower_bound(8);
    std::cout << "8 " << *eight << std::endl;

    auto nine = set1.upper_bound(8);
    std::cout << "9 " << *nine << std::endl;

    set1.erase(it, set1.end());

    //
    return 0;
}