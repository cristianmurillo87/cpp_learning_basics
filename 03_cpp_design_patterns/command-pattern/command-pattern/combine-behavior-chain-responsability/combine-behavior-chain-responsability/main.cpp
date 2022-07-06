//
//  main.cpp
//  combine-observer-chain-responsability-command-pattern
//
//  Created by Cristian on 16/04/22.
//

#include <iostream>
#include <vector>

// observer pattern
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

// command pattern
class Command
{
public:
    virtual ~Command() {};
    virtual void execute() = 0;
    virtual std::string get_message() = 0;
};

class SendMessageCommand: public Command
{
    std::string message;
    ChatGroup *group;
public:
    SendMessageCommand(ChatGroup *group, std::string message)
    : group(group), message(message) {};
    
    void execute() override
    {
        group->publish(message);
    }
    
    std::string get_message() override
    {
        return message;
    }
};

// chain of responsability pattern
class Handler
{
public:
    virtual ~Handler() {};
    // set next handler in the chain
    virtual Handler *set_next(Handler *next_validator) = 0;
    virtual std::string handle(Command *command) = 0;
};


class BaseHandler: public Handler
{
protected:
    Handler* next = nullptr;
public:
    virtual ~BaseHandler() {delete next;};
    
    // override methods from Handler
    Handler* set_next(Handler *next_validator) override
    {
        next = next_validator;
        return next_validator;
    }
    
    virtual std::string handle(Command *command)
    override
    {
        if (this->next)
        {
            return this->next->handle(command);
        }
        return "Success!";
    }
    
};

class NotEmptyValidator: public BaseHandler
{
public:
    NotEmptyValidator() {};
    
    std::string handle(Command *command)
    {
        puts("Checking if empty...");
        if(command->get_message().empty())
        {
            return "Please enter a value";
        }
        return BaseHandler::handle(command);
    }
};

class LengthValidator: public BaseHandler
{
private:
    int min_length;

public:
    LengthValidator(int min_length): min_length(min_length) {};
    
    std::string handle(Command *command)
    {
        puts("Checking string length ...");
        if (command->get_message().size() < min_length)
        {
            return "Please enter a value longer than " +
            std::to_string(min_length);
        }
        return BaseHandler::handle(command);
    }
};


class PostMessageHandler: public BaseHandler
{
public:
    std::string handle(Command *command)
    {
        command->execute();
        return "Message sent";
    };
};

int main(int argc, const char * argv[]) {
    ChatUser *user_1 = new ChatUser("Jim");
    ChatUser *user_2 = new ChatUser("Barb");
    ChatUser *user_3 = new ChatUser("Hannah");
    
    ChatGroup *group_1 = new ChatGroup("Gardening group");
    ChatGroup *group_2 = new ChatGroup("Dog-lovers group");
    
    // apply subscriber pattern
    group_1->subscribe(user_1);
    group_1->subscribe(user_2);
    
    group_2->subscribe(user_2);
    group_2->subscribe(user_3);
    
    // apply command pattern
    SendMessageCommand *empty_string_cmd = new SendMessageCommand(group_1, "");
    SendMessageCommand *too_short_cmd = new SendMessageCommand(group_1, "H");
    SendMessageCommand *msg_to_group_1_cmd =
        new SendMessageCommand(group_1, "Hello everyone in group 1");
    SendMessageCommand *msg_to_group_2_cmd =
        new SendMessageCommand(group_2, "Hello everyone in group 2!");
    
    
    
    
    Handler *send_message_chain = new BaseHandler;
    
    // apply chain of responsability pattern
    send_message_chain
    ->set_next(new NotEmptyValidator)
    ->set_next(new LengthValidator(2))
    ->set_next(new PostMessageHandler);
    
    std::cout << "Sending empty message:\n" <<
        send_message_chain->handle(empty_string_cmd) << "\n\n";
    
    std::cout << "Sending short message:\n" <<
        send_message_chain->handle(too_short_cmd) << "\n\n";
    
    std::cout << "Sending message to group 1:\n" <<
        send_message_chain->handle(msg_to_group_1_cmd) << "\n\n";

    std::cout << "Sending message to group 2:\n" <<
        send_message_chain->handle(msg_to_group_2_cmd) << "\n\n";
    
    
    delete user_1;
    delete user_2;
    delete user_3;
    delete group_1;
    delete group_2;
    delete empty_string_cmd;
    delete too_short_cmd;
    delete msg_to_group_1_cmd;
    delete msg_to_group_2_cmd;
    
    return 0;
}
