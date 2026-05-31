#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {0, 2, 4, 6, 8};

    int length1 = 5;
    int length2 = 5;
    int length3 = length1 + length2;

    int arr3[length3];

    int i = 0, j = 0, k = 0;

    // merge while both arrays have elements
    while (i < length1 && j < length2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    // copy remaining elements of arr1
    while (i < length1)
    {
        arr3[k++] = arr1[i++];
    }

    // copy remaining elements of arr2
    while (j < length2)
    {
        arr3[k++] = arr2[j++];
    }

    // output
    for (int k = 0; k < length3; k++)
    {
        cout << arr3[k] << "\t";
    }
}