#include <iostream>
using namespace std;

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 15, 20};
    int n = sizeof(A) / sizeof(A[0]);
    int B[21] = {0}; // array having index upto largest element
    for (int i = 0; i < n - 1; i++)
    {
        B[A[i]]++;
    }
    for (int i = 0; i < 21; i++)
    {
        if (B[i] > 1)
        {
            cout << i << "is duplicated " << B[i] << " times" << endl;
        }
    }
}