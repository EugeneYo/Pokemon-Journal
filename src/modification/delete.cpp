#include <delete.h>

using namespace std;

void deleteHunter(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
    }
    else
    {

        int i = selectHunter(hunter);
        Hunter deletedHunter = hunter.at(i);
        hunter.erase(hunter.begin() + i);
        writeHunter(hunter);

        SetConsoleTextAttribute(console, 12);
        printf("\n* Hunter %s %s has successfully deleted from the journal *\n", deletedHunter.firstName.c_str(), deletedHunter.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
}
void deletePokemon(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }
    int i = selectHunter(hunter);
    vector<Pokemon> pokemon = hunter.at(i).pokemon;
    Hunter hunt = hunter.at(i);

    if (pokemon.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* Hunter %s does not own any Pokemon yet *\n", hunt.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
    else
    {
        int k = selectPokemon(pokemon);
        Pokemon deletedPokemon = hunter.at(i).pokemon.at(k);
        pokemon.erase(pokemon.begin() + k);
        hunter.at(i).pokemon = pokemon;

        writeHunter(hunter);

        SetConsoleTextAttribute(console, 12);
        printf("\n* Pokemon %s has successfully deleted from the Hunter %s *\n", deletedPokemon.name.c_str(), hunt.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
}
void deleteStop(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }

    int i = selectHunter(hunter);
    vector<Pokemon_Stops> stop = hunter.at(i).pStop;
    Hunter hunt = hunter.at(i);

    if (stop.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* Hunter %s has not been to any Stop yet *\n", hunt.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
    else
    {

        int k = selectStop(stop);
        Pokemon_Stops deletedStop = hunter.at(i).pStop.at(k);
        stop.erase(stop.begin() + k);
        hunter.at(i).pStop = stop;
        writeHunter(hunter);

        SetConsoleTextAttribute(console, 12);
        printf("\n* Stop on %s at %s has successfully deleted from the Hunter %s *\n", deletedStop.date.c_str(), deletedStop.time.c_str(), hunt.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
}
void deleteRaid(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }

    int i = selectHunter(hunter);
    vector<Raid> raid = hunter.at(i).pRaid;
    Hunter hunt = hunter.at(i);

    if (raid.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* Hunter %s has not been to any Raid yet *\n", hunt.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
    else
    {

        int k = selectRaid(raid);
        Raid deletedRaid = hunter.at(i).pRaid.at(k);
        raid.erase(raid.begin() + k);
        hunter.at(i).pRaid = raid;
        writeHunter(hunter);

        SetConsoleTextAttribute(console, 12);
        printf("\n* Raid on %s at %s has successfully deleted from the Hunter %s *\n", deletedRaid.date.c_str(), deletedRaid.venue.c_str(), hunt.lastName.c_str());
        SetConsoleTextAttribute(console, 15);
    }
}
