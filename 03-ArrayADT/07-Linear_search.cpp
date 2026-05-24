#include <iostream>
using namespace std;
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    // to find key 6
    int key = 6;
    int index = -1;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
            index = i;
    }
    if (index != -1)
        cout << "The element is at index " << index << endl;
    else
        cout << "There is no such element present on array" << endl;
    return 0;
}