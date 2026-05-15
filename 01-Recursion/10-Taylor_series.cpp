// here we will find taylor series for e^x
// e^x=1+x+x^2/2!+x^3​/3!​+⋯upto n terms

// concept:e(x,0)=1
//e(x,1)=1+x/1 say 1+p/f
//e(x,2)=1+x+x^2/2!
//so for e(x,n) we call e(x,n-1) ann add it with p/f where p is power and f is factorial
#include <iostream>
using namespace std;
float e(int x, int n)
{
    static long int p = 1;
    static long int f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
        r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return (r + ((float) p / f));
}
int main()
{
    float r = e(4, 8);
    cout << "Taylor series:" << r << endl;
    return 0;
}

/*alternative method:
#include <iostream>
using namespace std;
float power(int x, int n);
float fact(int n);
float sum(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return power(x, n) / fact(n) + sum(x, n - 1);
}
float power(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(x * x, n / 2);
    else
        return x * power(x * x, (n - 1 )/ 2);
}
float fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
int main()
{
    float r = sum(4, 8);
    cout << "Taylor series:" << r << endl;
    return 0;
}
*/