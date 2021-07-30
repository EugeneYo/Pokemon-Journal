#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>

#include <class.h>
#include <hunter.h>
#include <color.h>
#include <selection.h>

int selectHunter(std::vector<Hunter> hunter);
int selectPokemon(std::vector<Pokemon> pokemon);
int selectStop(std::vector<Pokemon_Stops> pStop);
int selectRaid(std::vector<Raid> pRaid);
#endif