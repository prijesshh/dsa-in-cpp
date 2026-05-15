#include <iostream>
using namespace std;
float e(int x, int n)
{
    static double r = 1;
    if (n == 0)
        return r;
    else
    {
        r = 1 + ((float)x * r / n);
        return e(x, n - 1);
    }
}
int main()
{
    cout << e(4, 10) << endl;
    ;
}