
#include <validation.h>
using namespace std;

// bool validateDate(tm &timestruct)
// {
//     struct tm copy;
//     copy.tm_sec = timestruct.tm_sec;
//     copy.tm_min = timestruct.tm_min;
//     copy.tm_hour = timestruct.tm_hour;
//     copy.tm_mday = timestruct.tm_mday;
//     copy.tm_mon = timestruct.tm_mon;
//     copy.tm_year = timestruct.tm_year;
//     copy.tm_wday = timestruct.tm_wday;
//     copy.tm_yday = timestruct.tm_yday;
//     copy.tm_isdst = timestruct.tm_isdst;
//     // if time is not correct, res will return -1;
//     time_t res = mktime(&copy);
//     if (res < 0)
//     {
//         return false;
//     }
//     if (copy.tm_mday != timestruct.tm_mday || copy.tm_mon != timestruct.tm_mon || copy.tm_year != timestruct.tm_year)
//     {
//         return false;
//     }
//     return true;
// }

// void dateValid(string &date)
// {
//     struct tm tm;
//     memset(&tm, 0, sizeof(tm));
//     while (true)
//     {
//         // Read the date and assign the values to tm;
//         sscanf(date.c_str(), "%d-%d-%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
//         --tm.tm_mon;
//         tm.tm_year -= 1900;

//         // struct tm *check;
//         // check = &tm;

//         if (!validateDate(tm))
//         {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             printColor("Error !", 12);
//             cout << " Invalid date. Please enter a valid date: ";
//             cin >> date;
//         }
//         else
//         {
//             break;
//         }
//     };
//     time_t timeStamp = mktime(&tm);
//     char buff[50];
//     strftime(buff, 50, "%d-%m-%Y", localtime(&timeStamp));
//     string timeStr(buff);
//     date = timeStr;
// }
// bool validateTime(tm &timestruct)
// {
//     struct tm copy;
//     copy.tm_sec = timestruct.tm_sec;
//     copy.tm_min = timestruct.tm_min;
//     copy.tm_hour = timestruct.tm_hour;
//     copy.tm_mday = timestruct.tm_mday;
//     copy.tm_mon = timestruct.tm_mon;
//     copy.tm_year = timestruct.tm_year;
//     copy.tm_wday = timestruct.tm_wday;
//     copy.tm_yday = timestruct.tm_yday;
//     copy.tm_isdst = timestruct.tm_isdst;

//     // if time is not correct, res will return -1;
//     time_t res = mktime(&copy);
//     if (res < 0)
//     {
//         return false;
//     }
//     if (copy.tm_min != timestruct.tm_min || copy.tm_hour != timestruct.tm_hour)
//     {
//         return false;
//     }
//     return true;
// }
// void timeValid(string &time)
// {
//     struct tm tm;
//     memset(&tm, 0, sizeof(tm));
//     while (true)
//     {
//         unsigned tmp_hour, tmp_mins;
//         sscanf(time.c_str(), "%d:%d", &tmp_hour, &tmp_mins);

//         tm.tm_hour = tmp_hour;
//         tm.tm_min = tmp_mins;
//         tm.tm_mday = 15;
//         tm.tm_mon = 10;
//         tm.tm_year = 2020;
//         --tm.tm_mon;
//         tm.tm_year -= 1900;
//         // struct tm *check;
//         // check = &tm;

//         if (!validateTime(tm))
//         {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             printColor("Error !", 12);
//             cout << " Invalid time. Please enter a valid time: ";
//             cin >> time;
//         }
//         else
//         {
//             break;
//         }
//     };

//     time_t timeStamp = mktime(&tm);
//     char buff[50];
//     strftime(buff, 50, "%H:%M", localtime(&timeStamp));
//     string timeStr(buff);
//     time = timeStr;
// }

bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0));
}
bool validDatePattern(string date)
{
    regex date_pattern("^\\d{2}-\\d{2}-\\d{4}$");
    bool correct_date_pattern = 0;
    bool correct_leap_year_pattern = 0;
    bool correct_normal_year_pattern = 0;

    correct_date_pattern = regex_match(date, date_pattern);

    char *dissectDate = &date[0];
    int day, month, year;
    sscanf(dissectDate, "%d-%d-%d", &day, &month, &year);

    if (isLeapYear(year))
    {
        regex leap_year_pattern("^((([0][1-9]|[12][0-9])-02)|(([0][1-9]|[12][0-9]|[3][01])-[(01|03|05|07|08|10|12)])|(([0][1-9]|[12][0-9]|30)-[(04|06|09|11)]))-\\d{4}");
        correct_leap_year_pattern = regex_match(date, leap_year_pattern);
    }
    else
    {
        regex normal_year_pattern("^((([0][1-9]|[1][0-9]|[2][0-8])-02)|(([0][1-9]|[12][0-9]|[3][01])-(01|03|05|07|08|10|12))|(([0][1-9]|[12][0-9]|30)-(04|06|09|11)))-\\d{4}");
        correct_normal_year_pattern = regex_match(date, normal_year_pattern);
    }
    return ((correct_date_pattern && correct_leap_year_pattern) || (correct_date_pattern && correct_normal_year_pattern));
}
void dateValid(string &date)
{
    bool state = validDatePattern(date);
    while (state == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printColor("Error !", 12);
        cout << " Invalid date. Please enter a valid date: ";
        cin >> date;
        state = validDatePattern(date);
    }
}
bool validTimePattern(string time)
{
    regex time_pattern("^([01][0-9]|[2][0-4]):([0-5][0-9])$");
    bool correct_time_pattern = regex_match(time, time_pattern);
    return correct_time_pattern;
}
void timeValid(string &time)
{
    bool state = validTimePattern(time);
    while (state == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printColor("Error !", 12);
        cout << " Invalid time. Please enter a valid time: ";
        cin >> time;
        state = validTimePattern(time);
    }
}
int intValid(bool t, int num, int type)
{
    while (true)
    {
        if (t == true)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (type == 1)
            {
                printColor("Error !", 12);
                cout << " Invalid option. "
                     << "Please enter the available option : ";
                cin >> num;
            }
            else if (type == 2)
            {
                printColor("Error !", 12);
                cout << " Invalid CP. "
                     << "Please enter a valid CP : ";
                cin >> num;
            }
            else if (type == 3)
            {
                printColor("Error !", 12);
                cout << " Invalid level. "
                     << "Please enter a valid Level : ";
                cin >> num;
            }
            else
            {
                cout << ""
                     << "Please enter a valid integer : ";
                cin >> num;
            }
        }
        if (!cin.fail())
        {
            break;
        }
    }
    return num;
}
float floatValid(bool t, float num, int type)
{
    while (true)
    {
        if (t == true)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (type == 1)
            {
                printColor("Error !", 12);
                cout << " Invalid height. "
                     << "Please enter a valid Height : ";
                cin >> num;
            }
            else if (type == 2)
            {
                printColor("Error !", 12);
                cout << " Invalid weight. "
                     << "Please enter a valid Weight : ";
                cin >> num;
            }
            else
            {
                cout << ""
                     << "Please enter a valid float : ";
                cin >> num;
            }
        }
        if (!cin.fail())
        {
            break;
        }
    }
    return num;
}
void pokemonTypeValid(string &pokemonType)
{
    string type = pokemonType;
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    while (true)
    {
        if (type == "normal" || type == "ground" || type == "fire" || type == "fighting" || type == "water" || type == "grass" || type == "rock" || type == "electric" || type == "bug" || type == "physic" || type == "poison" || type == "dragon")
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            type[0] = toupper(type[0]);
            pokemonType = type;
            break;
        }
        else
        {
            printColor("\nError !", 12);
            cout << " Invalid Pokemon Type.\n";

            printf("%-34s: ", "Available options for Pokemon Type");
            SetConsoleTextAttribute(console, 9);
            printf("-%-10s  -%-10s  -%-10s  -%-10s\n%-36s-%-10s  -%-10s  -%-10s  -%-10s\n%-36s-%-10s  -%-10s  -%-10s  -%-10s\n", "Normal", "Ground", "Fire", "Fighting", " ", "Water", "Grass", "Rock", "Electric", " ", "Bug", "Physic", "Poison", "Dragon");
            SetConsoleTextAttribute(console, 15);

            cout << "Please enter one of the above options: ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);
        }
    }
}
void genderValid(string &gender)
{
    string type = gender;
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    while (true)
    {
        if (type == "male" || type == "female" || type == "agender")
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            type[0] = toupper(type[0]);
            gender = type;
            break;
        }
        else
        {
            printColor("\nError !", 12);
            cout << " Gender not recognized.\n";

            printf("%-29s: ", "Available options for Gender");
            SetConsoleTextAttribute(console, 9);
            printf("-%-8s-%-10s-%-10s\n", "Male", "Female", "Agender");
            SetConsoleTextAttribute(console, 15);

            cout << "Please enter one of the above options: ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);
        }
    }
}
void teamTypeValid(string &teamType)
{
    string type = teamType;
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    while (true)
    {
        if (type == "mystic" || type == "instinct" || type == "none")
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            type[0] = toupper(type[0]);
            teamType = type;
            break;
        }
        else
        {
            printColor("\nError !", 12);
            cout << " Invalid Team Type.\n";

            printf("%-32s: ", "Available options for Team Type");
            SetConsoleTextAttribute(console, 9);
            printf("-%-9s-%-10s -%-10s\n", "Mystic", "Instinct", "None");
            SetConsoleTextAttribute(console, 15);

            cout << "Please enter one of the above options: ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);
        }
    }
}
void emptyValid(string &input)
{

    while (true)
    {
        if (input.empty() || all_of(input.begin(), input.end(), [](char c)
                                    { return isspace(c); }))
        {
            printColor("\nError !", 12);
            cout << " Input is empty. ";
            cout << "Please enter again : ";
            getline(cin, input);
        }
        else
        {
            break;
        }
    }
}
