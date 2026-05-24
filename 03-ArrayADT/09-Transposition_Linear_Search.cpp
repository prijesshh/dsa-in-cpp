// we may search the key again so to reduce time complexity we move the searched key to i-1 from i
#include <iostream>
using namespace std;
void swap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    // to find key 4
    int key = 4;
    int index = -1;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
        {
            if (i > 0) // bcz we cant swap 0 and -1
                swap(arr[i], arr[i - 1]);

            index = i;
            break;
        }
    }
    if (index != -1)
        cout << "The element is at index " << index << endl;
    else
        cout << "There is no such element present on array" << endl;
    return 0;
}
