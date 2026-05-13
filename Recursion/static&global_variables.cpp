#include <iostream>
using namespace std;
/*A stack is created as , for every call each time a new variable
will be created inside the memory and it'll have its value this
is also know as local variable of a function*/
// Examples for local recursion
int local(int n)
{
    if (n > 0)
    {
        return local(n - 1) + n;
    }
    return 0;
}
/*If static variables are inside recursive function don’t show
them in each tracing tree write them in global or outside
variable and maintain a single copy of it*/
int staticv(int n)
{
    static int x = 0; // static variable recurssion
    if (n > 0)
    {
        x++;
        return staticv(n - 1) + x;
    }
    return 0;
}

int y = 0; // global variable decleration
int global(int n)
{
    if (n > 0)
    {
        y++;
        return global(n - 1) + y;
    }
    return 0;
}

int main()
{
    int n = 5;
    cout << "For local variable output is:" << local(n) << endl;
    cout << " Again For local variable output is:" << local(n) << endl;
    cout << "For static variable output is:" << staticv(n) << endl;
    cout << "Again for static variable output is:" << staticv(n) << endl;
    cout << "For global variable output is:" << global(n) << endl;
    cout << "Again For global variable output is:" << global(n) << endl;
    return 0;
}