#include <iostream>
using namespace std;
void display(int arr[], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}
void append(int (&arr)[10], int value, int &length, int size)
{
    if (length < size)
    {
        arr[length] = value;
        length++;
    }
    else
        cout << "No space left" << endl;
}
void insert(int (&arr)[10], int index, int value, int &length, int size)
{
    if (length >= size)
    {
        cout << "Array full, cannot insert" << endl;
        return;
    }
    else if (index >= 0 && index < length)
    {
        for (int i = length; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        length++;
    }
    else
        cout << "Invalid index" << endl;
}
int main()
{
    int arr[10] = {2, 3, 4, 5};
    int length = 4;
    int size;
    size = sizeof(arr) / sizeof(arr[0]);
    display(arr, length);
    append(arr, 6, length, size);
    display(arr, length);
    insert(arr, 0, 1, length, size);
    display(arr, length);
}