#include <iostream>

template <typename T, typename U>
class Person
{
public:
    T height;
    U weight;
    static int numOfPeople;
    Person(T height, U weight)
    {
        this->height = height;
        this->weight = weight;
        numOfPeople++;
    }

    void get_data()
    {
        std::cout << "Height (m): " << this->height << " and weight (kg): " << this->weight << std::endl;
    }
};

template <typename T, typename U>
int Person<T, U>::numOfPeople = 0;

int main()
{

    Person<double, int> person(1.7, 70);
    person.get_data();
    // always use the <datatype, datatype> sintaxis
    std::cout << "Number of people: " << Person<double, int>::numOfPeople << std::endl;
    return 0;
}