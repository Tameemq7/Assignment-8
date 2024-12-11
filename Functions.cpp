#include "Functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void greeting() {
    std::cout << "Press Enter to Continue";
    std::cin.get();
};

int recordCount() {
    std::ifstream file("data/data.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 0;
    }

    std::string line;
    int count = 0;
    bool inRecord = false;

    while (getline(file, line)) {
        if (line.empty()) {
            if (inRecord) {
                ++count;
                inRecord = false;
            }
        } else {
            inRecord = true;
        }
    }
    if (inRecord) ++count;
    file.close();
    return count;
};

void getInput(std::vector<CollegePerson*>& records) {
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return;
    }

    std::string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string name, university, college;
        int age, id;
        getline(ss, name, ',');
        ss >> age;
        ss.ignore(1);
        getline(ss, university, ',');
        getline(ss, college, ',');
        ss >> id;

        CollegePerson* person = new CollegePerson(name, age, university, college, id);

        float totalEarned = 0, totalPossible = 0;

        while (getline(file, line) && !line.empty()) {
            std::stringstream taskStream(line);
            std::string taskName;
            float earned, full;
            getline(taskStream, taskName, ','); 
            taskStream >> earned;
            taskStream.ignore(1); 
            taskStream >> full;

            totalEarned += earned;
            totalPossible += full;

            if(line.find_first_not_of(" \t\n\r") == std::string::npos) break;

            //debugging purposes
            //std::cout<<line;
            //std::cin.ignore();
        }

        //std::cout<<line;

        person->setEarned(totalEarned);
        person->setTotal(totalPossible);

        records.push_back(person);
    }

    file.close();
};


void calcGrades(std::vector<CollegePerson*>& records) {
    for (auto* person : records) {
        float grade = (person->getEarned() / person->getTotal()) * 100;
        person->setGrade(grade);

        if (grade > 94) {
            person->setGpa(4.5);
            person->setLetterGrade("A+");
        }
        else if (grade > 89) {
            person->setGpa(4.0);
            person->setLetterGrade("A");
        }
        else if (grade > 84) {
            person->setGpa(3.5);
            person->setLetterGrade("B+");
        }
        else if (grade > 79) {
            person->setGpa(3.0);
            person->setLetterGrade("B");
        }
        else if (grade > 74) {
            person->setGpa(2.5);
            person->setLetterGrade("C+");
        }
        else if (grade > 69) {
            person->setGpa(2.0);
            person->setLetterGrade("C");
        }
        else if (grade > 64) {
            person->setGpa(1.5);
            person->setLetterGrade("D+");
        }
        else if (grade > 60) {
            person->setGpa(1.0);
            person->setLetterGrade("D");
        }
        else {
            person->setGpa(0.0);
            person->setLetterGrade("F");
        }
    }
};

void display(const std::vector<CollegePerson*>& records) {
    std::cout << "UCD\n";
    std::cout << std::left<<std::setw(15)<<"Name"
              << std::setw(15) << "Age"
              << std::setw(15) << "ID"
              << std::setw(15) << "College"
              << std::setw(15) << "GPA"
              <<std::setw(15) << "Grade" << '\n';
    for (const auto* person : records) {
        if (person->getUniversity() == "UCD") {
            std::cout << std::left << std::setw(15) << person->getName()
                      << std::setw(15) << person->getAge()
                      << std::setw(15) << person->getId()
                      << std::setw(15) << person->getCollege()
                      << std::setw(15) << person->getGpa()
                      <<std::setw(15) << person->getLetterGrade() << '\n';
        }
    }

    std::cout << "\nMetro State\n";
    std::cout << std::setw(15) << "Name"
              << std::setw(15) << "Age"
              << std::setw(15) << "ID"
              << std::setw(15) << "College"
              << std::setw(15) << "GPA"
              <<std::setw(15) << "Grade" << '\n';
    for (const auto* person : records) {
        if (person->getUniversity() == "Metro State") {
            std::cout << std::left << std::setw(15) << person->getName()
                      << std::setw(15) << person->getAge()
                      << std::setw(15) << person->getId()
                      << std::setw(15) << person->getCollege()
                      << std::setw(15) << person->getGpa()
                      <<std::setw(15) << person->getLetterGrade() << '\n';
        }
    }
};