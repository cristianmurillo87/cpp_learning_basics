//
//  main.cpp
//  visitor-pattern
//
//  Created by Cristian on 18/04/22.
//

#include <iostream>

class Visitor
{
public:
    virtual void handle_person(const std::string &name, int age) = 0;
    virtual void handle_landmark(const std::string &name,
                                 const std::string &city_name) = 0;
    virtual void handle_car(const std::string &brand,
                            const std::string &model) = 0;
};

class DatabaseVisitor: public Visitor
{
public:
    void handle_person(const std::string &name, int age) override
    {
        std::cout << "Writing person to database: "
        << name << ", " << age << std::endl;
    }
    
    virtual void handle_landmark(const std::string &name,
                                 const std::string &city_name) override
    {
        std::cout << "Writing landmark to database: "
        << name << ", " << city_name << std::endl;
    }
    
    virtual void handle_car(const std::string &brand,
                            const std::string &model) override
    {
        std::cout << "Writing car to database: "
        << brand << ", " << model << std::endl;
    }
};

class TextFileVisitor: public Visitor
{
public:
    void handle_person(const std::string &name, int age) override
    {
        std::cout << "Writing person to file: "
        << name << ", " << age << std::endl;
    }
    
    virtual void handle_landmark(const std::string &name,
                                 const std::string &city_name) override
    {
        std::cout << "Writing landmark to file: "
        << name << ", " << city_name << std::endl;
    }
    
    virtual void handle_car(const std::string &brand,
                            const std::string &model) override
    {
        std::cout << "Writing car to file: "
        << brand << ", " << model << std::endl;
    }
};

class Person
{
    std::string name;
    int age;
public:
    Person(const std::string &name, int age): name(name), age(age) {};
    void accept(Visitor *v) {v->handle_person(name, age);};
};

class Landmark
{
    std::string name;
    std::string city_name;
public:
    Landmark(const std::string &name, const std::string city_name)
    :name(name), city_name(city_name) {};
    void accept(Visitor *v) {v->handle_landmark(name, city_name);};
};

class Car
{
    std::string brand;
    std::string model;
public:
    Car(const std::string &brand, const std::string &model)
    :brand(brand), model(model) {};
    void accept(Visitor *v) {v->handle_landmark(brand, model);};
};


int main(int argc, const char * argv[]) {
    Person person("John", 40);
    Landmark landmark("Eiffel Tower", "Paris");
    Car car("Chevrolet", "Camaro");
    
    DatabaseVisitor *dbv = new DatabaseVisitor;
    TextFileVisitor *tfv = new TextFileVisitor;
    
    person.accept(dbv);
    landmark.accept(dbv);
    car.accept(dbv);
    
    person.accept(tfv);
    landmark.accept(tfv);
    car.accept(tfv);
    
    delete dbv;
    delete tfv;
    
    return 0;
}
