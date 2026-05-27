#include <iostream>
using namespace std;
int RecBinary(int arr[], int key, int high, int low, int mid)
{
    if (high >= low)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
        {
            low = mid + 1;
            mid = (high + low) / 2;
            return RecBinary(arr, key, high, low, mid);
        }
        else
        {
            high = mid - 1;
            mid = (high + low) / 2;
            return RecBinary(arr, key, high, low, mid);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {4, 8, 10, 15, 18, 21, 24, 27, 293, 34, 37, 39, 41, 43};
    int key = 18;
    int length = sizeof(arr) / sizeof(arr[0]);
    int high = length - 1;
    int low = 0;
    int mid;
    mid = (high + low) / 2;
    int index;
    index = RecBinary(arr, key, high, low, mid);
    if (index == -1)
        cout << "Key not found on array";
    else
        cout << "key is at index " << index << endl;
}