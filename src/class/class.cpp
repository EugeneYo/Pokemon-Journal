
#include <class.h>
using namespace std;

/***************************************************** Structs *****************************************************/
Pokemon::Pokemon(string pokemon_name, string pokemon_type, int pokemon_cp, string pokemon_dateCaptured, float pokemon_height, float pokemon_weight)
{
    name = pokemon_name;
    type = pokemon_type;
    cp = pokemon_cp;
    dateCaptured = pokemon_dateCaptured;
    height = pokemon_height;
    weight = pokemon_weight;
}
void Pokemon::display(int i)
{
    printf("\t\t\t%-5d %-15s %-15s %-10d %-20s %-15.1f %-15.1f\n", i, name.c_str(), type.c_str(), cp, dateCaptured.c_str(), height, weight);
}

Pokemon_Stops::Pokemon_Stops(string stop_date, string stop_time, string stop_items)
{
    date = stop_date;
    time = stop_time;
    items = stop_items;
}

void Pokemon_Stops::display(int i)
{
    printf("\t\t\t%-5d %-15s %-15s %-15s\n", i, date.c_str(), time.c_str(), items.c_str());
}

Raid::Raid(string raid_date, string raid_time, string raid_venue)
{
    date = raid_date;
    time = raid_time;
    venue = raid_venue;
}

void Raid::display(int i)
{
    printf("\t\t\t%-5d %-15s %-15s %-15s\n", i, date.c_str(), time.c_str(), venue.c_str());
}

Hunter::Hunter(string hunter_firstName, string hunter_lastName, int hunter_level, string hunter_gender, string hunter_teamType, vector<Pokemon> hunter_pokemon, vector<Pokemon_Stops> hunter_pStop, vector<Raid> hunter_pRaid)
{
    firstName = hunter_firstName;
    lastName = hunter_lastName;
    level = hunter_level;
    gender = hunter_gender;
    teamType = hunter_teamType;
    pokemon = hunter_pokemon;
    pStop = hunter_pStop;
    pRaid = hunter_pRaid;
}
void Hunter::sortPokemon()
{
    sort(pokemon.begin(), pokemon.end(), [](const Pokemon &i, const Pokemon &j)
         { return i.cp > j.cp; });
}
void Hunter::displayDetails(int i)
{

    string line = "----------------------------------------------------------------------------------------------";
    string asterisk = "**********************************************************************************************";

    SetConsoleTextAttribute(console, 14);
    printf("\t\t\t%s \n", asterisk.c_str());                   // ************
    printf("\t\t\t%39d %9s %3s %-40d\n", i, "Hunter", " ", i); // 1   Hunter   1
    printf("\t\t\t%s \n", asterisk.c_str());                   // ************
    SetConsoleTextAttribute(console, 15);

    printf("\t\t\t%5s %-12s:     %-25s\n", " ", "First Name", firstName.c_str());
    printf("\t\t\t%5s %-12s:     %-25s\n", " ", "Last Name", lastName.c_str());
    printf("\t\t\t%5s %-12s:     %-25d\n", " ", "Level", level);
    printf("\t\t\t%5s %-12s:     %-25s\n", " ", "Gender", gender.c_str());
    printf("\t\t\t%5s %-12s:     %-25s\n\n", " ", "Team Type", teamType.c_str());

    SetConsoleTextAttribute(console, 14);
    printf("\t\t\t%-39s %10s %3s %-40s\n", "**************************************", "Pokemon", " ", "***************************************");
    printf("\t\t\t%5s %-15s %-15s %-10s %-20s %-15s %-15s\n", " ", "Name", "Type", "CP", "Date Captured", "Height", "Weight");
    SetConsoleTextAttribute(console, 15);

    int k = 0;
    for (auto &p : pokemon)
    {
        k++;
        p.display(k);
    }
    printf("\n"); //

    SetConsoleTextAttribute(console, 14);
    printf("\t\t\t%-39s %9s %4s %-40s\n", "**************************************", "Stops", " ", "***************************************");
    printf("\t\t\t%5s %-15s %-15s %-10s \n", " ", "Date", "Time", "Item");
    SetConsoleTextAttribute(console, 15);

    k = 0;
    for (auto &ps : pStop)
    {
        k++;
        ps.display(k);
    }
    printf("\n"); //

    SetConsoleTextAttribute(console, 14);
    printf("\t\t\t%-39s %9s %4s %-40s\n", "**************************************", "Raids", " ", "***************************************");
    printf("\t\t\t%5s %-15s %-15s %-10s \n", " ", "Date", "Time", "Venue");
    SetConsoleTextAttribute(console, 15);

    k = 0;
    for (auto &pr : pRaid)
    {
        k++;
        pr.display(k);
    }
    printf("\n"); //

    SetConsoleTextAttribute(console, 14);
    printf("\t\t\t%s\n\n", asterisk.c_str()); // ************
    SetConsoleTextAttribute(console, 15);
}

void Hunter::display(int i)
{
    printf("\t\t\t%-5d %-15s %-15s %-10d %-20s %-15s\n", i, firstName.c_str(), lastName.c_str(), level, gender.c_str(), teamType.c_str());
}
