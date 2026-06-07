#include <iostream>
using namespace std;

int main()
{
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 15, 20};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n - 1; i++) // i<n-1 bcz i+1 must always be valid
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1; // to count

            while (j < n && A[j] == A[i])
                j++;

            cout << A[i] << " is duplicate " << (j - i) << " times" << endl;

            i = j; //helps to skip rem duplicated elements
        }
    }
}
