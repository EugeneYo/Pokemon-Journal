#include <add.h>
using namespace std;
void addHunter(vector<Hunter> &hunter)
{

    string s;
    string firstName;
    string lastName;
    int level;
    string gender;
    string teamType;
    vector<Pokemon> pokemon;
    vector<Pokemon_Stops> pStop;
    vector<Raid> pRaid;

    SetConsoleTextAttribute(console, 11);
    cout << "--------Filling up the Hunter details--------\n";
    SetConsoleTextAttribute(console, 15);
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "First Name: ";
    getline(cin, firstName);
    emptyValid(firstName);
    cout << "Last Name: ";
    getline(cin, lastName);
    emptyValid(lastName);

    cout << "Level: ";
    cin >> level;
    level = intValid(cin.fail(), level, 3);

    cout << "Gender: ";
    cin >> gender;
    genderValid(gender);

    cout << "Team Type: ";
    cin >> teamType;
    teamTypeValid(teamType);

    do
    {
        string input;
        SetConsoleTextAttribute(console, 14);
        cout << "\n[1] --Adding a Pokemon details for this hunter? (Y/N) : ";
        SetConsoleTextAttribute(console, 15);

        cin >> input;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input == "Y" || input == "y")
        {

            string name;
            string type;
            int cp;
            string dateCaptured;
            float height;
            float weight;

            cout << "Pokemon Name: ";
            getline(cin, name);

            cout << "Pokemon Type: ";
            cin >> type;
            pokemonTypeValid(type);

            cout << "Pokemon CP: ";
            cin >> cp;
            cp = intValid(cin.fail(), cp, 2);

            cout << "Date Captured (dd-mm-yyyy): ";
            cin >> dateCaptured;
            dateValid(dateCaptured);

            cout << "Height: ";
            cin >> height;
            height = floatValid(cin.fail(), height, 1);

            cout << "Weight: ";
            cin >> weight;
            weight = floatValid(cin.fail(), weight, 2);

            Pokemon poke = Pokemon(name, type, cp, dateCaptured, height, weight);
            pokemon.push_back(poke);
        }
        else
        {
            break;
        }

    } while (true);

    do
    {
        string input;

        SetConsoleTextAttribute(console, 14);
        cout << "\n[2] --Adding a Stop details for this hunter? (Y/N) : ";
        SetConsoleTextAttribute(console, 15);
        cin >> input;

        if (input == "Y" || input == "y")
        {
            string date;
            string time;
            string items;

            cout << "Stop Date (dd-mm-yyy): ";
            cin >> date;
            dateValid(date);

            cout << "Stop Time (hh:mm): ";
            cin >> time;
            timeValid(time);

            cout << "Stop Item: ";
            cin >> items;

            Pokemon_Stops poke = Pokemon_Stops(date, time, items);
            pStop.push_back(poke);
        }
        else
        {
            break;
        }

    } while (true);

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        string input;
        SetConsoleTextAttribute(console, 14);
        cout << "\n[3] --Adding a Raid details for this hunter? (Y/N) : ";
        SetConsoleTextAttribute(console, 15);
        cin >> input;

        if (input == "Y" || input == "y")
        {
            string date;
            string time;
            string venue;

            cout << "Raid Date (dd-mm-yyy): ";
            cin >> date;
            dateValid(date);

            cout << "Raid Time (hh:mm): ";
            cin >> time;
            timeValid(time);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Raid Venue: ";
            getline(cin, venue);
            emptyValid(venue);

            Raid poke = Raid(date, time, venue);
            pRaid.push_back(poke);
        }
        else
        {
            break;
        }

    } while (true);

    Hunter hunt = Hunter(firstName, lastName, level, gender, teamType, pokemon, pStop, pRaid);
    hunt.sortPokemon();
    hunter.push_back(hunt);
    writeHunter(hunter);
    int i = 0;
    for (auto &h : hunter)
    {
        i++;
        h.displayDetails(i);
    }

    SetConsoleTextAttribute(console, 10);
    printf("\n* Hunter %s %s has successfully registered into the Journal *\n", firstName.c_str(), lastName.c_str());
    SetConsoleTextAttribute(console, 15);
}
void addPokemonToHunter(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }
    int i = selectHunter(hunter);
    Hunter added = hunter.at(i);

    string name;
    string type;
    int cp;
    string dateCaptured;
    float height;
    float weight;

    SetConsoleTextAttribute(console, 11);
    printf("------ Adding new Pokemon to Hunter %s ------\n", added.lastName.c_str());
    SetConsoleTextAttribute(console, 15);

    cout << "Pokemon Name: ";
    cin >> name;
    cout << "Pokemon Type: ";
    cin >> type;
    pokemonTypeValid(type);
    cout << "CP: ";
    cin >> cp;
    cp = intValid(cin.fail(), cp, 2);
    cout << "Date Captured (dd-mm-yyy): ";
    cin >> dateCaptured;
    dateValid(dateCaptured);
    cout << "Height: ";
    cin >> height;
    height = floatValid(cin.fail(), height, 1);
    cout << "Weight: ";
    cin >> weight;
    weight = floatValid(cin.fail(), height, 2);

    Pokemon poke = Pokemon(name, type, cp, dateCaptured, height, weight);
    hunter.at(i).pokemon.push_back(poke);
    hunter.at(i).sortPokemon();

    added = hunter.at(i);
    added.displayDetails(++i);
    writeHunter(hunter);

    SetConsoleTextAttribute(console, 10);
    printf("\n* Added new Pokemon %s to Hunter %s *\n", poke.name.c_str(), added.lastName.c_str());
    SetConsoleTextAttribute(console, 15);
}
void addStopToHunter(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }
    int i = selectHunter(hunter);
    Hunter added = hunter.at(i);

    string date;
    string time;
    string items;

    SetConsoleTextAttribute(console, 11);
    printf("------ Adding new Stop to Hunter %s ------\n", added.lastName.c_str());
    SetConsoleTextAttribute(console, 15);

    cout << "Date (dd-mm-yyy): ";
    cin >> date;
    dateValid(date);
    cout << "Time (hh:mm): ";
    cin >> time;
    timeValid(time);
    cout << "Item: ";
    cin >> items;

    Pokemon_Stops stop = Pokemon_Stops(date, time, items);
    hunter.at(i).pStop.push_back(stop);

    added = hunter.at(i);
    added.displayDetails(++i);
    writeHunter(hunter);

    SetConsoleTextAttribute(console, 10);
    printf("\n* Added new Stop to Hunter %s *\n", added.lastName.c_str());
    SetConsoleTextAttribute(console, 15);
}
void addRaidToHunter(vector<Hunter> &hunter)
{
    if (hunter.empty())
    {
        SetConsoleTextAttribute(console, 12);
        printf("\n* There is no hunter registered yet *\n");
        SetConsoleTextAttribute(console, 15);
        return;
    }
    int i = selectHunter(hunter);
    Hunter added = hunter.at(i);

    string date;
    string time;
    string venue;

    SetConsoleTextAttribute(console, 11);
    printf("------ Adding new Raid to Hunter %s ------\n", added.lastName.c_str());
    SetConsoleTextAttribute(console, 15);

    cout << "Date (dd-mm-yyy): ";
    cin >> date;
    dateValid(date);
    cout << "Time (hh:mm): ";
    cin >> time;
    timeValid(time);
    cout << "Venue: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, venue);
    emptyValid(venue);

    Raid raid = Raid(date, time, venue);
    hunter.at(i).pRaid.push_back(raid);

    added = hunter.at(i);
    added.displayDetails(++i);
    writeHunter(hunter);

    SetConsoleTextAttribute(console, 10);
    printf("\n* Added new Raid at %s to Hunter %s *\n", raid.venue.c_str(), added.lastName.c_str());
    SetConsoleTextAttribute(console, 15);
}
