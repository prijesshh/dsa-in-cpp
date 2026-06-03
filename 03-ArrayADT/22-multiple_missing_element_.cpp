#include <iostream>
using namespace std;
void method1()
{
    int arr[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int low = arr[0];
    int length = sizeof(arr) / sizeof(arr[0]);
    int high = arr[length - 1];
    int diff = low - 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] - i != diff) // element is missing
        {
            while (arr[i] - i > diff)
            {
                cout << "Missing element:" << diff + i << endl;
                diff++;
            }
        }
    }
}
void method2() // faster->uses hash table
{
    int arr[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int low = 3;
    int length = sizeof(arr) / sizeof(arr[0]);
    int high = 12;
    int aux[13] = {0}; // high+1
    for (int i = 0; i < length; i++)
    {
        aux[arr[i]]++;
    }
    cout << endl;
    for (int i = low; i <= high; i++)
    {
        if (aux[i] == 0)
        {
            cout << "Missing element:" << i << endl;
        }
    }
}
int main()
{
    method1();
    method2();
}