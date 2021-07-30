#ifndef ADD_H
#define ADD_H

#include <iostream>

#include <validation.h>
#include <hunter.h>
#include <selection.h>
#include <class.h>
#include <color.h>
#include <add.h>

void addHunter(std::vector<Hunter> &hunter);
void addPokemonToHunter(std::vector<Hunter> &hunter);
void addStopToHunter(std::vector<Hunter> &hunter);
void addRaidToHunter(std::vector<Hunter> &hunter);

#endif