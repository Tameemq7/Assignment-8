#include "CollegePerson.h"

CollegePerson::CollegePerson()
    : Person(), university(""), college(""), id(0), earned(0), total(0), grade(0), gpa(0), letterGrade("") {}

CollegePerson::CollegePerson(const std::string& name, int age, const std::string& university,
                             const std::string& college, int id)
    : Person(name, age), university(university), college(college), id(id), earned(0), total(0), grade(0), gpa(0),
      letterGrade("") {}

std::string CollegePerson::getUniversity() const { return university; }
std::string CollegePerson::getCollege() const { return college; }
int CollegePerson::getId() const { return id; }
float CollegePerson::getEarned() const { return earned; }
float CollegePerson::getTotal() const { return total; } 
float CollegePerson::getGrade() const { return grade; }
float CollegePerson::getGpa() const { return gpa; }
std::string CollegePerson::getLetterGrade() const { return letterGrade; }

void CollegePerson::setUniversity(const std::string& university) { this->university = university; }
void CollegePerson::setCollege(const std::string& college) { this->college = college; }
void CollegePerson::setId(int id) { this->id = id; }
void CollegePerson::setEarned(float earned) { this->earned = earned; }
void CollegePerson::setTotal(float total) { this->total = total; }
void CollegePerson::setGrade(float grade) { this->grade = grade; }
void CollegePerson::setGpa(float gpa) { this->gpa = gpa; }
void CollegePerson::setLetterGrade(const std::string& letterGrade) { this->letterGrade = letterGrade; }