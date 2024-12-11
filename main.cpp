#include <iostream>
#include <vector>
#include "Functions.h"
#include "CollegePerson.h"

int main() {
    std::vector<CollegePerson*> records;

    greeting();

    getInput(records);

    calcGrades(records);

    display(records);



    for(auto* person : records) {
        delete person;
    }

    std::cout << "Program ended." << std::endl;

    return 0;
};