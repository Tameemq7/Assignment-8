#ifndef COLLEGEPERSON_H
#define COLLEGEPERSON_H

#include "Person.h"
#include <string>

class CollegePerson : public Person {
private:
    std::string university;
    std::string college;
    int id;
    float earned;
    float total;
    float grade;
    float gpa;
    std::string letterGrade;

public:
    CollegePerson();
    CollegePerson(const std::string& name, int age, const std::string& university, const std::string& college, int id);

    std::string getUniversity() const;
    std::string getCollege() const;
    int getId() const;
    float getEarned() const;
    float getTotal() const;
    float getGrade() const;
    float getGpa() const;
    std::string getLetterGrade() const;

    void setUniversity(const std::string& university);
    void setCollege(const std::string& college);
    void setId(int id);
    void setEarned(float earned);
    void setTotal(float total);
    void setGrade(float grade);
    void setGpa(float gpa);
    void setLetterGrade(const std::string& letterGrade);
};

#endif