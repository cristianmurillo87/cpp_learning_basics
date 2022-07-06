#include <iostream>
#include <vector>

// Unlike arrays, vectors always know their size
void print_vector(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\t";
    }
    std::cout << std::endl;
}

// In order to modify vectors inside a function
// and the canges be kept in place, vectors
// must be past to functions as reference
void append_to_vector(std::vector<int> &vec, int new_element)
{
    vec.push_back(new_element);
}

// Vectors are a C++11 feature, when compiling, use the -std=c++11 flag
int main()
{
    std::vector<int> data = {1, 2, 3};

    // add elements
    data.push_back(4);
    std::cout << data[3] << std::endl;
    std::cout << "The size of the vector is: " << data.size() << std::endl;

    // remove the last element
    data.pop_back();
    std::cout << "The size of the vector is: " << data.size() << std::endl;

    print_vector(data);
    append_to_vector(data, 5);
    print_vector(data);

    return 0;
}