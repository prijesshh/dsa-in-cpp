#include <iostream>
using namespace std;
int fib(int n)
{
    int t0 = 0, t1 = 1;
    int s = 0;
    if (n <= 1)
        return n;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        }
        return s;
    }
}
int main()
{
    cout << fib(7) << endl;
}