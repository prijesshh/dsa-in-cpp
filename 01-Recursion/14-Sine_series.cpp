#include <iostream>
using namespace std;
double sine(int x, int n, bool reset_parameter)
{
    double s;
    static double r;
    static double p;
    static double f;
    static bool reset;
    reset = reset_parameter;
    if (reset)
    {
        p = x;
        f = 1;
        r = 0;
    }
    if (n == 1)
        return x;
    else
    {
        s = sine(x, n - 1, false);
        p = p * x * x;
        f = f * (2 * n - 1) * (2 * n - 2); // this gives 2n-1 !for n=2 2n-1 gives odd value ie 3 and 2n-2 gives even value ie 2
        // we look at two AS one is 1,3,5,7,... and other is 0,2,4,6,...(bcz we need 2 at n=2 so we are starting from 0,2,..)

        if (n % 2 == 0)
            r = s - (p / f);
        else
            r = s + (p / f);
        return r;
    }
}
int main()
{
    cout << sine(5, 10, true) << endl;
}
/*
Sin(x) Taylor Series - Recursive Method

Goal:Compute sin(x) = x - x³/3! + x⁵/5! - x⁷/7! + ...
How it works:

1.Base case (n=1):Return x (first term)

2.Recursive case (n>=2):
   - Get previous sum: s = sine(x, n-1)
   - Update power: p *= x*x→ accumulates x³, x⁵, x⁷...
   - Update factorial: f *= (2n-1)(2n-2)→ accumulates 3!, 5!, 7!...
   - Alternate signs: if n is even, subtract; if odd, add
   - Return updated sum

Example (n=3):
- n=1: return x
- n=2: s = x, p = x³, f = 3!, return x - x³/6
- n=3: s = x - x³/6, p = x⁵, f = 5!, return x - x³/6 + x⁵/120

Each recursion level adds one more term to the series.
*/