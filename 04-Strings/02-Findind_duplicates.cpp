#include <iostream>
using namespace std;
int main()
{
    char a[] = "finding";
    int count[26] = {0};               // consider only lower case aplhabtes then there re 25 alphabets
    for (int i = 0; a[i] != '\0'; i++) // until end of string
    {
        count[a[i] - 97]++; // a=97
    }
    for (int i = 0; i != 26; i++)
    {
        if (count[i] > 1)
            cout << char(i + 97) << " is duplicate " << count[i] << " times" << endl;
    }
}