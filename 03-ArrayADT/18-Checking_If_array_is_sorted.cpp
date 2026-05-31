#include <iostream>
using namespace std;
int main()
{
    int arr[] = {-2, -1, 0, 1, 2};
    bool test1 = true, test2 = true;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            test1 = false;
        }
        if (arr[i] > arr[i + 1]) // to check ascending
        {
            test2 = false;
        }
    }
    if (test1 && test2) // chcek this condn first
        cout << "all elements are equal";
    else if (test1)
        cout << "decending";
    else if (test2)
        cout << "acending";
    else
        cout << "not sorted";
    return 0;
}