#include <iostream>

class ClassA
{
public:
    // without the virtual keyword, all child classes of this class
    // would execute this method instead of its eventual implementation
    // in such child classes.
    // this problem would occur with pointers and references
    virtual void output()
    {
        std::cout << "I'm an object of class A" << std::endl;
    }
};

class ClassB : public ClassA
{
public:
    // the override keyword indicates the implementation for a child class
    // of a method declared as virtual in the parent class
    void output() override
    {
        std::cout << "I'm an object of class B" << std::endl;
    }
};

int main()
{
    ClassA a;
    ClassB b;

    ClassA &a1 = a;
    ClassA &a2 = b;

    a1.output();
    a2.output();

    return 0;
}