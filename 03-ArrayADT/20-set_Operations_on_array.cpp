#include <iostream>
using namespace std;
void intersection()
{
    bool check;
    int a1[] = {3, 5, 10, 4, 6};
    int a2[] = {12, 4, 7, 2, 5};
    int n = 5;
    int m = 5;
    int a3[m + n];
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        check = false;
        for (int j = 0; j < m; j++)
        {
            if (a1[i] == a2[j])
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            a3[t++] = a1[i];
        }
    }
    for (int k = 0; k < t; k++)
    {
        cout << a3[k] << endl;
    }
}
int main()
{
    // unioun:fisrt we will copy all the elements of first array then we will copy only thoose elements of
    // second array which is not present in first array
    int a1[] = {3, 5, 10, 4, 6};
    int a2[] = {12, 4, 7, 2, 5};
    int n = 5;
    int m = 5;
    int a3[m + n];
    int i, j, k = 0, t = n;
    bool check;
    for (i = 0; i < n; i++)
    {
        a3[k++] = a1[i];
    }
    for (j = 0; j < m; j++)
    {
        check = true;
        for (k = 0; k < n; k++)
        {
            if (a3[k] == a2[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            a3[t] = a2[j];
            t++;
        }
    }
    // display unioun
    for (k = 0; k < t; k++)
    {
        cout << a3[k] << endl;
    }
    cout << endl;
    intersection();
    return 0;
}