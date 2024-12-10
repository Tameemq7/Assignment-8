#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "CollegePerson.h"
#include <vector>

void greeting();
int recordCount();
void getInput(std::vector<CollegePerson*>& records);
void calcGrades(std::vector<CollegePerson*>& records);
void display(const std::vector<CollegePerson*>& records);

#endif