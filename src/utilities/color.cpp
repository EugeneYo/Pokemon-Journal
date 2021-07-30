#include <color.h>

using namespace std;

void printColor(string str, int k)
{
    SetConsoleTextAttribute(console, k);
    cout << str;
    SetConsoleTextAttribute(console, 15);
}