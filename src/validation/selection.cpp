#include <selection.h>
using namespace std;

int selectHunter(vector<Hunter> hunter)
{
    displayHunters(hunter);

    int i = 0;
    bool state = true;
    do
    {
        string input;
        cout << "Please select a Hunter by number : ";
        cin >> input;
        try
        {
            i = stoi(input);
            i--;
            Hunter selectedHunter = hunter.at(i);
            cout << endl;
            state = false;
        }
        catch (...)
        {
            printColor("\nError !", 12);
            cout << " There is no such selection" << endl;
            continue;
        }
    } while (state);

    return i;
}
int selectPokemon(vector<Pokemon> pokemon)
{

    string line = "----------------------------------------------------------------------------------------------";
    printf("\t\t\t%s \n", line.c_str());
    cout << "\t\t\t                                           POKEMONS                                           " << endl;
    printf("\t\t\t%s \n", line.c_str());
    printf("\t\t\t%5s %-15s %-15s %-10s %-20s %-15s %-15s\n", " ", "Name", "Type", "CP", "Date Captured", "Height", "Weight");
    printf("\t\t\t%s \n", line.c_str());

    int i = 0;
    for (auto &p : pokemon)
    {
        i++;
        SetConsoleTextAttribute(console, 6);
        p.display(i);
    }
    cout << "\n";
    SetConsoleTextAttribute(console, 15);

    bool state = true;
    do
    {
        string input;
        cout << "Please select a Pokemon by number : ";
        cin >> input;
        try
        {
            i = stoi(input);
            i--;
            Pokemon selectedPokemon = pokemon.at(i);
            cout << endl;
            state = false;
        }
        catch (...)
        {
            printColor("\nError !", 12);
            cout << " There is no such selection" << endl;
            continue;
        }
    } while (state);
    return i;
}
int selectStop(vector<Pokemon_Stops> pStop)
{

    string line = "----------------------------------------------------------------------------------------------";
    printf("\t\t\t%s \n", line.c_str());
    cout << "\t\t\t                                          Stops                                           " << endl;
    printf("\t\t\t%s \n", line.c_str());
    printf("\t\t\t%-5s %-15s %-15s %-15s\n", " ", "Date", "Time", "Item");
    printf("\t\t\t%s \n", line.c_str());

    int i = 0;
    for (auto &ps : pStop)
    {
        i++;
        SetConsoleTextAttribute(console, 6);
        ps.display(i);
    }
    cout << "\n";
    SetConsoleTextAttribute(console, 15);

    bool state = true;
    do
    {
        string input;
        cout << "Please select a Stop by number : ";
        cin >> input;
        try
        {
            i = stoi(input);
            i--;
            Pokemon_Stops selectedStop = pStop.at(i);
            cout << endl;
            state = false;
        }
        catch (...)
        {
            printColor("\nError !", 12);
            cout << " There is no such selection" << endl;
            continue;
        }
    } while (state);
    return i;
}
int selectRaid(vector<Raid> pRaid)
{
    string line = "----------------------------------------------------------------------------------------------";
    printf("\t\t\t%s \n", line.c_str());
    cout << "                                          Raids                                           " << endl;
    printf("\t\t\t%s \n", line.c_str());
    printf("\t\t\t%-5s %-15s %-15s %-15s\n", " ", "Date", "Time", "Venue");
    printf("\t\t\t%s \n", line.c_str());

    int i = 0;
    for (auto &pr : pRaid)
    {
        i++;
        SetConsoleTextAttribute(console, 6);
        pr.display(i);
    }
    cout << "\n";
    SetConsoleTextAttribute(console, 15);

    bool state = true;
    do
    {
        string input;
        cout << "Please select a Raid by number : ";
        cin >> input;
        try
        {
            i = stoi(input);
            i--;
            Raid selectedRaid = pRaid.at(i);
            cout << endl;
            state = false;
        }
        catch (...)
        {
            printColor("\nError !", 12);
            cout << " There is no such selection" << endl;
            continue;
        }
    } while (state);
    return i;
}
