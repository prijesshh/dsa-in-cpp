//we cant incerease size of array because array has contigious memory 
//say A[3] where A[0] has address 40 A[1] has 44 and A[2] has address of 48
//the if we want to increase the array size the next location should be 52 which may be already ocuppied
#include <iostream>
using namespace std;
int main()
{
    int *p;
    p = new int[5]{0, 1, 2, 3, 4};
    ;
    int *q;
    q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    p = q; // now p points to the same address that was pointed by q
    q = NULL;
    return 0;
}