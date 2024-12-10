#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person();
    Person(const std::string& name, int age);

    std::string getName() const;
    int getAge() const;

    void setName(const std::string& name);
    void setAge(int age);

};

#endif