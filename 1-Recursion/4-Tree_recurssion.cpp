/* If a recursive function calling itself more than one time then it is tree
recursion*/
#include <iostream>
using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}
int main()
{
    fun(3);
    return 0;
}
/*RECURSION TREE DIAGRAM (from Image 1):

                              fun(3)
                            /       \
                        fun(2)       fun(2)
                       /     \       /     \
                   fun(1)  fun(1) fun(1) fun(1)
                   /   \    /  \   /  \   /  \
                fun(0) f(0) f(0) f(0) f(0) f(0) f(0) f(0)
                  |     |    |    |    |    |    |    |
                  X     X    X    X    X    X    X    X  (Base cases - return)



    - Total function calls: 1 + 2 + 4 + 8 = 15 calls
    - Time Complexity: O(2^n) - EXPONENTIAL

    - Space Complexity: O(n)
    - Maximum recursion depth = n
    - Only n frames on stack at any time
    - Not O(2^n) because old calls are removed
    MAX STACK DEPTH: 4
    (When fun(3) → fun(2) → fun(1) → fun(0) all on stack)*/