// if n=4 then output=1+2+3+4
/*it is Arithmetic Series (AP)
A series where difference between terms is constant.
Formula for sum:
n/2 . (2a+(n−1)d) */
// that is output=n(n+1)/2

#include <iostream>
using namespace std;
int sum(int n)
{
    if (n > 0)
    {
        return n + sum(n - 1);
    }
    return 0;
}
int main()
{

    cout << "Required sum is:" << sum(4) << endl;
    return 0;
}