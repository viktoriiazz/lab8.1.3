#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s)
{
    if (strlen(s) < 4)
        return 0;

    int k = 0;

    for (int i = 0; s[i + 3] != 0; i++)
    {
        if (strchr(s + i + 1, s[i]) - s == i + 1 &&
            strchr(s + i + 2, s[i]) - s == i + 2 &&
            strchr(s + i + 3, s[i]) - s == i + 3)
        {
            k++;
            i += 3;
        }
    }

    return k;
}

char* Change(char* s)
{
    if (strlen(s) < 4)
        return 0;

    char* t = new char[strlen(s)];
    *t = 0;

    for (int i = 0; s[i + 3] != 0; i++)
    {
        if (strchr(s + i + 1, s[i]) - s == i + 1 &&
            strchr(s + i + 2, s[i]) - s == i + 2 &&
            strchr(s + i + 3, s[i]) - s == i + 3)
        {
            strcat(t, "**");
            i += 3;
        }
        else
        {
            strncat(t, s + i, 1);
        }
    }

    strcpy(s, t);

    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of 4 same characters" << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}