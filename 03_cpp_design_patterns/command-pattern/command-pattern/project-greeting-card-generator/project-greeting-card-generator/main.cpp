//
//  main.cpp
//  project-greeting-card-generator
//
//  Created by Cristian on 18/04/22.
//

#include <iostream>
#include <vector>

class Visitor
{
public:
    virtual std::string handle_person(const std::string &name, int age) = 0;
};

class Person
{
    std::string name;
    int age;
public:
    Person(const std::string &name, int age): name(name), age(age) {};
    std::string accept(Visitor *v) {return v->handle_person(name, age);};
};

class GreetingCardTemplate: public Visitor
{
    std::string from;
protected:
    virtual std::string intro(const std::string &to)
    {
        return "Dear, " + to + ",\n";
    }
    
    virtual std::string occasion()
    {
        return "Just writing to say hi! Hope all is well with you";
    }
    
    virtual std::string closing(const std::string &from)
    {
        return "Sincerely,\n" + from + "\n";
    }
    
public:
    GreetingCardTemplate(const std::string &from): from(from) {};
    ~GreetingCardTemplate() {};
    std::string generate_card_for(Person *person)
    {
        return person->accept(this);
    }
    std::string handle_person(const std::string &name, int age)
    {
        return intro(name) + occasion() + closing(from);
    }
    
};


class BirthdayCardTemplate: public GreetingCardTemplate
{
protected:
    std::string occasion() override
    {
        return "Happy birthday! Have a wonderful day and lots of cake\n";
    }
public:
    BirthdayCardTemplate(const std::string &from)
    : GreetingCardTemplate(from) {};
};

class NewYearsCardTemplate: public GreetingCardTemplate
{
protected:
    std::string intro(const std::string &to) override
    {
        return to + "!!!\n";
    }
    
    std::string occasion() override
    {
        return "Happy New Years!!! See you at the gym tomorrow\n";
    }
public:
    NewYearsCardTemplate(const std::string &from)
    : GreetingCardTemplate(from) {};
};


class GreetingCardGenerator
{
    GreetingCardTemplate * temp;
    std::vector<Person*> people;
public:
    void add_person(Person *person) {people.push_back(person);};
    void set_template(GreetingCardTemplate *new_temp) {temp = new_temp;};
    std::vector<std::string> send_greeting_cards()
    {
        std::vector<std::string> greeting_cards;
        for (auto person: people)
        {
            greeting_cards.push_back(temp->generate_card_for(person));
        }
        return greeting_cards;
    }
};

int main(int argc, const char * argv[]) {
    Person *person_1 = new Person("John", 40);
    Person *person_2 = new Person("Joan", 80);
    Person *person_3 = new Person("Brenda", 25);
    
    GreetingCardGenerator *generator = new GreetingCardGenerator;
    generator->add_person(person_1);
    generator->add_person(person_2);
    generator->add_person(person_3);
    
    generator->set_template(new BirthdayCardTemplate("Bob"));
    
    for (auto card: generator->send_greeting_cards())
    {
        std::cout << card << std::endl;
    }
    
    generator->set_template(new NewYearsCardTemplate("Penelope"));
    for (auto card: generator->send_greeting_cards())
    {
        std::cout << card << std::endl;
    }
    
    
    delete person_1;
    delete person_2;
    delete person_3;
    
    return 0;
}
