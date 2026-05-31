#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {4, 5, 6, 7, 8, 9, 22, 25, 87};
    int insert = 18;
    int length = 9;
    int i = length - 1;
    while (arr[i] > 0 && arr[i] > insert)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = insert;
    length++;
    for (i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}