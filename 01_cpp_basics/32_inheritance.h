#ifndef TEACHER_H
#define TEACHER_H

#include <vector>
#include <string>
#include "31_multfile_class_declaration.h"

class Teacher : public User
{
    int experience;

public:
    Teacher();
    Teacher(std::string first_name, std::string last_name, std::string status);
    Teacher(std::string first_name, std::string last_name, std::string status, int experience);
    std::vector<std::string> classes_teaching;
    void output();
};

#endif