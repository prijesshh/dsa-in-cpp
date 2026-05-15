/*Indirect recursion is a type of recursion where a function does not
 call itself directly, but instead calls another function, and that
 second function (or a chain of functions) eventually calls the first
 function again.

example:
A → B → A (cycle)
So the recursion happens indirectly through other functions.*/

#include <iostream>
using namespace std;
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        funA(n / 2);
    }
}
int main()
{
    funA(20);
    return 0;
}