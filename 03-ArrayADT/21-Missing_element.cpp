/*suppose we have an array which has n natura number where we have to find
missing element*/
#include <iostream>
using namespace std;
int main()
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 12;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = sum + arr[i];
    }
    int sum_of_n = n * (n + 1) / 2;
    int missing_element = sum_of_n - sum;
    cout << "Missing element is:" << missing_element;
}