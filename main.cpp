#include <iostream>

// #include <string>
// #include <iomanip>
// #include <fstream>
// #include <stdlib.h>
// #include <assert.h>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <ctime>
// #include <sstream>
// #include <cstring>
// #include <cctype>

#include <class.h>
#include <validation.h>
#include <add.h>
#include <delete.h>
#include <color.h>

using namespace std;
/**************************************************** Loops ***************************************************/
void searchHunterLoop(vector<Hunter> hunter)
{
    // system("CLS");
    int input4 = 0;
    string search;
    do
    {
        SetConsoleTextAttribute(console, 11);
        cout << "\n------Search Hunter By------" << endl;
        SetConsoleTextAttribute(console, 15);
        cout << "1) First Name" << endl;
        cout << "2) Last Name" << endl;
        cout << "3) Level" << endl;
        cout << "4) Gender" << endl;
        cout << "5) Team Type" << endl;
        cout << "6) Back to Main Menu\n\n";

        cout << "Option : ";
        cin >> input4;
        input4 = intValid(cin.fail(), input4, 1);
        cout << "\n";

        switch (input4)
        {
        case 1:
            getline(cin, search);
            cout << "Search Hunters by first name : ";
            getline(cin, search);
            cout << endl;
            search = trim(search);
            searchHunter(hunter, "firstName", search);
            break;
        case 2:
            getline(cin, search);
            cout << "Search Hunters by last name : ";
            getline(cin, search);
            cout << endl;
            search = trim(search);
            searchHunter(hunter, "lastName", search);
            break;
        case 3:
            getline(cin, search);
            cout << "Search Hunters by level : ";
            getline(cin, search);
            cout << endl;
            search = trim(search);
            searchHunter(hunter, "level", search);
            break;
        case 4:
            getline(cin, search);
            cout << "Search Hunters by gender : ";
            getline(cin, search);
            cout << endl;
            search = trim(search);
            searchHunter(hunter, "gender", search);
            break;
        case 5:
            getline(cin, search);
            cout << "Search Hunters by team type : ";
            getline(cin, search);
            cout << endl;
            search = trim(search);
            searchHunter(hunter, "teamType", search);
            break;
        case 6:
            break;
        default:
            cout << "*Please enter the available option*\n";
            break;
        }
    } while (input4 != 6);
}
void addNewEntryLoop(vector<Hunter> &hunter)
{

    int input2 = 0;
    do
    {
        SetConsoleTextAttribute(console, 11);
        cout << "\n----------Add new entry----------" << endl;
        SetConsoleTextAttribute(console, 15);
        cout << "1) Register a new Hunter" << endl;
        cout << "2) Add new Pokemon to an existing Hunter" << endl;
        cout << "3) Add new Stop to an existing Hunter" << endl;
        cout << "4) Add new Raid to an existing Hunter" << endl;
        cout << "5) Back to Main Menu \n\n";

        cout << "Option : ";
        cin >> input2;
        cout << "\n";
        input2 = intValid(cin.fail(), input2, 1);

        switch (input2)
        {
        case 1:
            // Register a new hunter
            addHunter(hunter);
            break;
        case 2:
            // Add new pokemon
            addPokemonToHunter(hunter);
            break;
        case 3:
            // Add new stop
            addStopToHunter(hunter);
            break;
        case 4:
            // Add new raid
            addRaidToHunter(hunter);
            break;
        case 5:
            // Return back to Main Menu
            break;
        default:
            cout << "*Please enter the available option*\n";
            break;
        }

    } while (input2 != 5);
}
void deleteEntryLoop(vector<Hunter> &hunter)
{
    int input3 = 0;
    do
    {
        SetConsoleTextAttribute(console, 11);
        cout << "\n----------Delete Entry----------" << endl;
        SetConsoleTextAttribute(console, 15);
        cout << "1) Delete an existing Hunter" << endl;
        cout << "2) Delete a Pokemon from a Hunter" << endl;
        cout << "3) Delete a Stop from a Hunter" << endl;
        cout << "4) Delete a Raid from a Hunter" << endl;
        cout << "5) Back to Main Menu\n\n";

        cout << "Option : ";
        cin >> input3;
        cout << "\n";
        input3 = intValid(cin.fail(), input3, 1);

        switch (input3)
        {
        case 1:
            deleteHunter(hunter);
            break;
        case 2:
            deletePokemon(hunter);
            break;
        case 3:
            deleteStop(hunter);
            break;
        case 4:
            deleteRaid(hunter);
            break;
        case 5:
            break;
        default:
            cout << "*Please enter the available option*\n";
            break;
        }

    } while (input3 != 5);
}

/**************************************************** MAIN***************************************************/
int main()
{
    // system("Color 0F");

    vector<Hunter> hunter;
    readHunter(hunter);
    bool state = true;
    int input = 0;

    do
    {
        // system("CLS");
        //Create a list and let user to choose
        SetConsoleTextAttribute(console, 14);
        cout << "\n\n WELCOME to Pokemon Journal \n\n";
        SetConsoleTextAttribute(console, 11);
        cout << "---------Main Menu---------" << endl;
        SetConsoleTextAttribute(console, 15);
        cout << "1) Show all Hunters details" << endl;
        cout << "2) Add new entry" << endl;
        cout << "3) Delete an entry" << endl;
        cout << "4) Search Hunters" << endl;
        cout << "5) Exit The Program\n\n";
        cout << "Option: ";
        cin >> input;
        input = intValid(cin.fail(), input, 1);
        switch (input)
        {
        case 1:
            displayHuntersDetails(hunter);
            break;
        case 2:
            addNewEntryLoop(hunter);
            break;
        case 3:
            deleteEntryLoop(hunter);
            break;
        case 4: // Search Hunters with First Name, Last Name, Level, Gender, Team Type
            searchHunterLoop(hunter);
            break;
        case 5:
            writeHunter(hunter);
            cout << "Saving data and exiting the program...";
            break;

        default:
            cout << "Please enter the available option.";
            break;
        }
    } while (input != 5);
    return 0;
}
