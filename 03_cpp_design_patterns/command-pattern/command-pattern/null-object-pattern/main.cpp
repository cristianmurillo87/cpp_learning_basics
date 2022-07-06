//
//  main.cpp
//  null-object
//
//  Created by Cristian on 18/04/22.
//

#include <iostream>
#include <stdio.h>

class Logger
{
public:
    virtual ~Logger() {};
    virtual void log(const std::string &message) = 0;
};

class ConsoleLogger: public Logger
{
public:
    void log(const std::string &message) override
    {
        std::cout << message << std::endl;
    }
};

class FileLogger: public Logger
{
    std::string file_path;
public:
    FileLogger(const std::string &file_path): file_path(file_path) {};
    void log(const std::string &message) override
    {
        std::cout << "Printing message to file: " << file_path
        << ": " << message << std::endl;
    }
};

class ApiLogger: public Logger
{
    std::string url;
public:
    ApiLogger(const std::string &url): url(url) {};
    void log(const std::string &message) override
    {
        std::cout << "Sending message to api: " << url
        << ": " << message << std::endl;
    }
};

class NullLogger: public Logger
{
    void log(const std::string &message) override {};
};

class SomeTask
{
    Logger *logger = nullptr;
public:
    SomeTask() {
        logger = new NullLogger;
    }
    SomeTask(Logger *logger): logger(logger) {};
    ~SomeTask() {delete logger;};
    void execute()
    {
        // some actions here
        logger->log("Did some stuff");
        
        // some other actions here
        logger->log("Did some other stuff");
        
        // some more actions here
        logger->log("Did some more stuff");
    }
};

int main(int argc, const char * argv[]) {
    SomeTask task_1(new ConsoleLogger);
    SomeTask task_2(new FileLogger("logs.txt"));
    SomeTask task_3(new ApiLogger("loggingsite.com/api/logs"));
    SomeTask task_4;
    
    task_1.execute();
    task_2.execute();
    task_3.execute();
    task_4.execute();
    
    return 0;
}
