#include <iostream>
using namespace std;
int comb(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return comb(n - 1, r - 1) + comb(n - 1, r);
}
int main()
{
    cout << comb(4, 3);
    return 0;
}