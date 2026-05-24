#include <iostream>
using namespace std;
void display(int arr[], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}
int main()
{
    int arr[] = {1, 2, 9, 3, 4, 5};
    int length = 6;
    display(arr, length);
    int index = 2;
    // to delet element of index 2
    // first check if index lies in our array or not
    if (index < length && index >= 0)
    {
        for (int i = index; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
        display(arr, length);
    }
    else
        cout << "Index out of range";
}
// time complexity is O(n)