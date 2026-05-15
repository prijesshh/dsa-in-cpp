/*Nested recursion is a type of recursion where a function calls itself,
but inside its own argument.

A function call is passed as a parameter to the same function.*/

// in this code if n>100 output is 91 else n-10
#include <iostream>
using namespace std;
int fun(int n)
{
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));
}
int main()
{
    cout << fun(96) << endl;
}