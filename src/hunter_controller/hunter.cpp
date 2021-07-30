#include <hunter.h>
using namespace std;

void readHunter(vector<Hunter> &hunter)
{
    string data;
    bool state = true;

    string firstName;
    string lastName;
    int level;
    string gender;
    string teamType;

    vector<Pokemon> pokemon;
    string pName;
    string pType;
    int pCP;
    string pDateCaptured;
    float pHeight;
    float pWeight;

    vector<Pokemon_Stops> pStop;
    string sDate;
    string sTime;
    string sItems;

    vector<Raid> pRaid;
    string rDate;
    string rTime;
    string rVenue;

    ifstream readFile;
    try
    {
        readFile.open(DATA, ios::in);

        while (!readFile.eof())
        {
            getline(readFile, data); //
            getline(readFile, data); //
            getline(readFile, data); // *******
            getline(readFile, data); // 1 Hunter 1
            getline(readFile, data); // *******

            readFile >> data;        // First
            readFile >> data;        // Name
            readFile >> data;        // :
            getline(readFile, data); // Yeoh Xuan
            firstName = trim(data);

            readFile >> data;        // Last
            readFile >> data;        // Name
            readFile >> data;        // :
            getline(readFile, data); // Kok Eugene
            lastName = trim(data);

            readFile >> data; // Level
            readFile >> data; // :
            readFile >> data; // 15
            level = stoi(data);

            readFile >> data;   // Gender
            readFile >> data;   // :
            readFile >> gender; // Male

            readFile >> data;     // Team
            readFile >> data;     // Type
            readFile >> data;     // :
            readFile >> teamType; // Fire

            getline(readFile, data); //
            getline(readFile, data); //
            getline(readFile, data); // ****** Pokemon ******
            getline(readFile, data); // Name Type CP Date Captured Height Weight
            while (readFile >> data)
            {
                if (data.find("****") != string::npos)
                {
                    break;
                }
                else
                {
                    string cp, ht, wt;
                    readFile >> pName;
                    readFile >> pType;
                    readFile >> cp;

                    readFile >> pDateCaptured;
                    readFile >> ht;
                    readFile >> wt;
                    try
                    {
                        pCP = stoi(cp);
                        pHeight = stof(ht);
                        pWeight = stof(wt);
                    }
                    catch (...)
                    {
                    }
                    Pokemon poke = Pokemon(pName, pType, pCP, pDateCaptured, pHeight, pWeight);
                    pokemon.push_back(poke);
                }
            }

            getline(readFile, data); // Stops ********
            getline(readFile, data); // Date Time Item
            while (readFile >> data)
            {
                if (data.find("****") != string::npos)
                {
                    break;
                }
                else
                {
                    readFile >> sDate;
                    readFile >> sTime;
                    readFile >> sItems;

                    Pokemon_Stops stop = Pokemon_Stops(sDate, sTime, sItems);
                    pStop.push_back(stop);
                }
            }

            getline(readFile, data); // Raids ******
            getline(readFile, data); // Date Time Venue
            while (readFile >> data)
            {
                if (data.find("****") != string::npos)
                {
                    break;
                }
                else
                {
                    readFile >> rDate;
                    readFile >> rTime;
                    getline(readFile, data);
                    rVenue = trim(data);

                    Raid raid = Raid(rDate, rTime, rVenue);
                    pRaid.push_back(raid);
                }
            }

            Hunter hunt = Hunter(firstName, lastName, level, gender, teamType, pokemon, pStop, pRaid);
            hunt.sortPokemon();
            hunter.push_back(hunt);
            pokemon.clear();
            pStop.clear();
            pRaid.clear();
        }
    }
    catch (...)
    {
        printColor("\n\n ! Error !\n", 12);
        cout << "Unable to read the file either due to the ";
        printColor("file does not exist ", 12);
        cout << "or ";
        printColor("the structure of the file is not the same as the program computed\n\n", 12);
        printColor("New file will be created upon saving \n\nProceeding to Main Menu...", 10);
    }

    readFile.close();
}
void writeHunter(vector<Hunter> hunter)
{
    FILE *pFile;
    pFile = fopen(DATA, "w");

    string asterisk = "**********************************************************************************************";

    int i = 0;
    for (auto &h : hunter)
    {
        fprintf(pFile, "\n\n");
        i++;
        fprintf(pFile, "%s \n", asterisk.c_str());                   // ***********
        fprintf(pFile, "%39d %9s %3s %-40d\n", i, "Hunter", " ", i); // 1  Hunter  1
        fprintf(pFile, "%s \n", asterisk.c_str());                   // ***********
        fprintf(pFile, "%5s %-12s: %-25s\n", " ", "First Name", h.firstName.c_str());
        fprintf(pFile, "%5s %-12s: %-25s\n", " ", "Last Name", h.lastName.c_str());
        fprintf(pFile, "%5s %-12s: %-25d\n", " ", "Level", h.level);
        fprintf(pFile, "%5s %-12s: %-25s\n", " ", "Gender", h.gender.c_str());
        fprintf(pFile, "%5s %-12s: %-25s\n\n", " ", "Team Type", h.teamType.c_str());

        fprintf(pFile, "%-39s %10s %3s %-40s\n", "**************************************", "Pokemon", " ", "***************************************");
        fprintf(pFile, "%5s %-15s %-15s %-10s %-20s %-15s %-15s\n", " ", "Name", "Type", "CP", "Date Captured", "Height", "Weight");

        vector<Pokemon> pokemon = h.pokemon;
        int k = 0;
        for (auto &p : pokemon)
        {
            k++;
            fprintf(pFile, "%-5d %-15s %-15s %-10d %-20s %-15.1f %-15.1f\n", k, p.name.c_str(), p.type.c_str(), p.cp, p.dateCaptured.c_str(), p.height, p.weight);
        }
        fprintf(pFile, "\n");

        fprintf(pFile, "%-39s %9s %4s %-40s\n", "**************************************", "Stops", " ", "***************************************");
        fprintf(pFile, "%5s %-15s %-15s %-10s \n", " ", "Date", "Time", "Item");

        vector<Pokemon_Stops> pStop = h.pStop;
        k = 0;
        for (auto &ps : pStop)
        {
            k++;
            fprintf(pFile, "%-5d %-15s %-15s %-15s\n", k, ps.date.c_str(), ps.time.c_str(), ps.items.c_str());
        }
        fprintf(pFile, "\n"); //

        fprintf(pFile, "%-39s %9s %4s %-40s\n", "**************************************", "Raids", " ", "***************************************");
        fprintf(pFile, "%5s %-15s %-15s %-10s \n", " ", "Date", "Time", "Venue");

        vector<Raid> pRaid = h.pRaid;
        k = 0;
        for (auto &pr : pRaid)
        {
            k++;
            fprintf(pFile, "%-5d %-15s %-15s %-15s\n", k, pr.date.c_str(), pr.time.c_str(), pr.venue.c_str());
        }
        fprintf(pFile, "\n"); //

        fprintf(pFile, "%s", asterisk.c_str()); // ************
    }
    fclose(pFile);
}
void displayHuntersDetails(vector<Hunter> hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }
    int i = 0;
    for (auto &h : hunter)
    {
        i++;
        h.displayDetails(i);
    }
    system("pause");
}
void displayHunters(vector<Hunter> hunter)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    string line = "----------------------------------------------------------------------------------------------";

    printf("\t\t\t%s \n", line.c_str());
    cout << "\t\t\t                                           Hunters                                          " << endl;
    printf("\t\t\t%s \n", line.c_str());

    printf("\t\t\t%5s %-15s %-15s %-10s %-20s %-15s\n", " ", "First Name", "Last Name", "Level", "Gender", "Team Type");
    printf("\t\t\t%s \n", line.c_str());

    int i = 0;
    for (auto &h : hunter)
    {
        i++;
        SetConsoleTextAttribute(console, 6);

        h.display(i);
    }
    SetConsoleTextAttribute(console, 15);

    printf("\n");
}
void searchHunter(vector<Hunter> &hunter, string searchBy, string input)
{
    vector<Hunter> result;

    if (searchBy == "firstName")
    {
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        for (auto &h : hunter)
        {
            string firstName = h.firstName;
            transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
            if (firstName == input)
            {
                result.push_back(h);
            }
        }
    }
    else if (searchBy == "lastName")
    {
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        for (auto &h : hunter)
        {
            string lastName = h.lastName;
            transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
            if (lastName == input)
            {
                result.push_back(h);
            }
        }
    }
    else if (searchBy == "teamType")
    {
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        for (auto &h : hunter)
        {
            string teamType = h.teamType;
            transform(teamType.begin(), teamType.end(), teamType.begin(), ::tolower);
            if (teamType == input)
            {
                result.push_back(h);
            }
        }
    }
    else if (searchBy == "gender")
    {
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        for (auto &h : hunter)
        {
            string gender = h.gender;
            transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
            if (gender == input)
            {
                result.push_back(h);
            }
        }
    }
    else if (searchBy == "level")
    {

        int lvl;
        bool state = true;
        do
        {

            try
            {
                lvl = stoi(input);
                state = false;
            }
            catch (...)
            {
                cout << "Please enter a valid integer : ";
                cin >> input;
                cout << "\n";
                continue;
            }
        } while (state);

        for (auto &h : hunter)
        {
            if (h.level == lvl)
            {
                result.push_back(h);
            }
        }
    }

    if (result.empty())
    {
        SetConsoleTextAttribute(console, 12);
        cout << "No result is found.\n"
             << endl;
        SetConsoleTextAttribute(console, 15);
    }
    else
    {
        displayHunters(result);
        bool state = true;
        do
        {
            string input;
            cout << "Please select a hunter to view his/her details (number):";
            cin >> input;
            cout << "\n";
            try
            {
                int i = stoi(input);
                i--;
                Hunter hunter = result.at(i);
                hunter.displayDetails(++i);
                system("pause");
                cout << endl;
                state = false;
            }
            catch (...)
            {
                printColor("Error !", 12);
                cout << " There is no such selection" << endl;
                continue;
            }
        } while (state);
    }
}
