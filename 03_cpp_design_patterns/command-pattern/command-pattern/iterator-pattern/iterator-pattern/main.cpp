//
//  main.cpp
//  iterator-pattern
//
//  Created by Cristian on 18/04/22.
//
#include <iostream>
#include <vector>

class NumberIterator
{
public:
    virtual ~NumberIterator() {};
    virtual int next() = 0;
    virtual bool is_finished() = 0;
};

class ForwardsIterator: public NumberIterator
{
    int current_position;
    std::vector<int> &numbers;
public:
    ForwardsIterator(std::vector<int> &numbers)
    : current_position(0), numbers(numbers) {};
    
    int next() override
    {
        int current = numbers.at(current_position);
        current_position += 1;
        return current;
    }
    
    bool is_finished() override
    {
        return current_position >= numbers.size();
    }
};

class BackwardsIterator: public NumberIterator
{
    int current_position;
    std::vector<int> &numbers;
public:
    BackwardsIterator(std::vector<int> &numbers)
    : numbers(numbers), current_position(0) {};
    
    int next() override
    {
        int current = numbers.at(numbers.size() - current_position - 1);
        current_position += 1;
        return current;
    }
    
    bool is_finished() override
    {
        return current_position >= numbers.size();
    }
};

class NumberCollection
{
    std::vector<int> numbers;
public:
    NumberCollection(const std::vector<int> &numbers): numbers(numbers) {};
    NumberIterator *get_forwards_iterator()
    {
        return new ForwardsIterator(numbers);
    }
    
    NumberIterator *get_backwards_iterator()
    {
        return new BackwardsIterator(numbers);
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    NumberCollection nc(numbers);
    
    NumberIterator *fi = nc.get_forwards_iterator();
    NumberIterator *bi = nc.get_backwards_iterator();
    
    while(!fi->is_finished())
    {
        std::cout << fi->next() << ", ";
    }
    
    std::cout << "\n";
    
    std::cout << "Iterating through the numbers backwards: \n";
    
    while(!bi->is_finished())
    {
        std::cout << bi->next() << ", ";
    }
    
    std::cout << "\n";
    
    delete fi;
    delete bi;
    
    return 0;
}
