#include <iostream>
using namespace std;
void display(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}
void reverse_swap(int arr[], int length)
{
    int temp;
    for (int i = 0; i < length / 2; i++) // loop uptolength/2
    {
        temp = arr[length - 1 - i];
        arr[length - 1 - i] = arr[i];
        arr[i] = temp;
    }
    display(arr, length);
}
void reverse_auxuillary(int arr[], int length)
{
    int aux[length];
    for (int i = 0; i < length; i++)
    {
        aux[length - 1 - i] = arr[i]; // reverse in auxuillary array
    }
    for (int i = 0; i < length; i++)
    {
        arr[i] = aux[i]; // save reversed in orginal array
    }
    display(arr, length);
}
void left_shift(int arr[], int length)
{
    for (int i = 1; i <= length; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[length - 1] = 0;
    display(arr, length);
}
void right_rotate(int arr[], int length)
{
    int temp;
    temp = arr[0];
    for (int i = 0; i < length - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = temp;
    display(arr, length);
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    reverse_swap(arr, length);
    cout << "\n";
    left_shift(arr, length);
    cout << "\n";
    int array[] = {1, 2, 3, 4, 5};
    right_rotate(array, length);
}
/* note:
when you pass an array to a function like:

void reverse(int arr[])

it becomes a pointer (int* arr), not a full array. So this:

sizeof(arr)

returns the size of a pointer, not the actual array size.*/