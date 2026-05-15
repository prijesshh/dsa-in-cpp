/* Here the first statement inside the function is recursive call and
all the processing of this function will be done after that
• In head recursion the function doesn't have to process any
operation at the time of function calling it has to do everything at
the time of returning such functions are head recursion

Head Recursion to Loop
• Although it is possible but It is difficult to convert head recursion
into a loop function*/
#include <iostream>
using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n << endl;
    }
}
int main()
{
    fun(3);
    return 0;
}