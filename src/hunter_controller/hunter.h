#ifndef HUNTER_H
#define HUNTER_H

#include <iostream>
#include <fstream>

#include <class.h>
#include <trim.h>
#include <color.h>
#include <hunter.h>

#define DATA "./src/data/Hunters.txt"

void readHunter(std::vector<Hunter> &hunter);
void writeHunter(std::vector<Hunter> hunter);
void displayHuntersDetails(std::vector<Hunter> hunter);
void displayHunters(std::vector<Hunter> hunter);
void searchHunter(std::vector<Hunter> &hunter, std::string searchBy, std::string input);
#endif
