#include <iostream>
using namespace std;
int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int hash[26] = {0};
    bool angram = true;
    for (int i = 0; A[i] != '\0'; i++)
    {
        hash[A[i] - 97]++;
    }
    for (int i = 0; B[i] != '\0'; i++)
    {
        hash[B[i] - 97]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != 0)
        {
            angram = false;
            break;
        }
    }
    if (angram)
        cout << "strings are angram";
    else
        cout << "not angram";
}