// F(n)=F(n−1)+F(n−2),F(0)=0,F(1)=1
#include <iostream>
using namespace std;
int f[100]; // global variable
int fib(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
        {
            f[n - 2] = fib(n - 2);
        }
        if (f[n - 1] == -1)
        {
            f[n - 1] = fib(n - 1);
        }
        f[n] = f[n - 2] + f[n - 1];
        return f[n];
    }
}
int main()
{
    // intialize gloabl variabel
    for (int i = 0; i < 100; i++)
        f[i] = -1; // bcz no term has -1 value
    cout << fib(7) << endl;
}