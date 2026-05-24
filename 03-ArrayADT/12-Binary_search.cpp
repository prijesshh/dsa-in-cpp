#include <iostream>
using namespace std;
int binary(int arr[], int key, int high, int low, int mid)
{
    while (high > low)
    {
        mid = (high + low) / 2; // here we take the floor value ie 5.5->5
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
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
    index = binary(arr, key, high, low, mid);
    if (index == -1)
        cout << "Key not found on array";
    else
        cout << "key is at index " << index << endl;
}