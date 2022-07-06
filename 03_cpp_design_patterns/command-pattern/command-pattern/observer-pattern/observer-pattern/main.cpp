//
//  main.cpp
//  observer-pattern
//
//  Created by Cristian on 16/04/22.
//

#include <iostream>
#include <vector>

class Subscriber{
public:
    virtual void notify(const std::string &publisher_name,
                        const std::string &message) = 0;
    virtual std::string get_name() = 0;
};

class Publisher
{
public:
    virtual void subscribe(Subscriber *subscriber) = 0;
    virtual void unsubscribe(Subscriber *subscriber) = 0;
    virtual void publish(const std::string &message) = 0;
};

class ChatGroup: public Publisher
{
    std::string group_name;
    std::vector<Subscriber*> subscribers;
public:
    ChatGroup(const std::string group_name): group_name(group_name) {};
    virtual void subscribe(Subscriber *subscriber) override
    {
        this->subscribers.push_back(subscriber);
    };
    virtual void unsubscribe(Subscriber *subscriber) override
    {
        subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
            [subscriber](Subscriber *s){
            return s->get_name() == subscriber->get_name();
        }), subscribers.end());
    };
    virtual void publish(const std::string &message) override
    {
        for(auto subscriber: subscribers)
        {
            subscriber->notify(group_name, message);
        }
    }
};

class ChatUser: public Subscriber
{
    std::string user_name;
public:
    explicit ChatUser(const std::string &name): user_name(name) {};
    void notify(const std::string &publisher_name,
                const std::string &message) override
    {
        std::cout << user_name << " received a new message from "
        << publisher_name << ": " << message << "\n";
    };
    
    std::string get_name() override { return user_name; };
};

int main(int argc, const char * argv[]) {
    ChatUser *user_1 = new ChatUser("Jim");
    ChatUser *user_2 = new ChatUser("Barb");
    ChatUser *user_3 = new ChatUser("Hannah");
    
    ChatGroup *group_1 = new ChatGroup("Gardening group");
    ChatGroup *group_2 = new ChatGroup("Dog-lovers group");
    
    group_1->subscribe(user_1);
    group_1->subscribe(user_2);
    
    group_2->subscribe(user_2);
    group_2->subscribe(user_3);
    
    group_1->publish("Special sale on gardening supplies!");
    group_2->publish("Happy national dog day");
    
    
    delete user_1;
    delete user_2;
    delete user_3;
    delete group_1;
    delete group_2;
    
    return 0;
}
