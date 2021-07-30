#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <regex>

#include <trim.h>
#include <structs.h>
#include <color.h>
#include <validation.h>

// bool validateDate(tm *timestruct);
// void dateValid(std::string &date);
// bool validateTime(tm *timestruct);
// void timeValid(std::string &time);

bool isLeapYear(int year);
bool validDatePattern(std::string date);
void dateValid(std::string &date);

bool validTimePattern(std::string time);
void timeValid(std::string &time);

int intValid(bool t, int num, int type);
float floatValid(bool t, float num, int type);
void pokemonTypeValid(std::string &pokemonType);
void genderValid(std::string &gender);
void teamTypeValid(std::string &teamType);
void emptyValid(std::string &input);

#endif
