#ifndef DELETE_H
#define DELETE_H

#include <iostream>

#include <hunter.h>
#include <selection.h>
#include <structs.h>
#include <color.h>
#include <delete.h>

void deleteHunter(std::vector<Hunter> &hunter);
void deletePokemon(std::vector<Hunter> &hunter);
void deleteStop(std::vector<Hunter> &hunter);
void deleteRaid(std::vector<Hunter> &hunter);

#endif