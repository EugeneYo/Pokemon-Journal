#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <color.h>
#include <class.h>

/***************************************************** Structs *****************************************************/
class Pokemon
{
public:
    std::string name;
    std::string type;
    int cp;
    std::string dateCaptured;
    float height;
    float weight;

    Pokemon(std::string pokemon_name, std::string pokemon_type, int pokemon_cp, std::string pokemon_dateCaptured, float pokemon_height, float pokemon_weight);
    void display(int i);
};

class Pokemon_Stops
{

public:
    std::string date;
    std::string time;
    std::string items;

    Pokemon_Stops(std::string stop_date, std::string stop_time, std::string stop_items);
    void display(int i);
};

class Raid
{
public:
    std::string date;
    std::string time;
    std::string venue;

    Raid(std::string raid_date, std::string raid_time, std::string raid_venue);
    void display(int i);
};

class Hunter
{
public:
    std::string firstName;
    std::string lastName;
    int level;
    std::string gender;
    std::string teamType;
    std::vector<Pokemon> pokemon;
    std::vector<Pokemon_Stops> pStop;
    std::vector<Raid> pRaid;
    Hunter(std::string hunter_firstName, std::string hunter_lastName, int hunter_level, std::string hunter_gender, std::string hunter_teamType, std::vector<Pokemon> hunter_pokemon, std::vector<Pokemon_Stops> hunter_pStop, std::vector<Raid> hunter_pRaid);
    void sortPokemon();
    void displayDetails(int i);
    void display(int i);
};

#endif