// a^n=a*a*a....*a upto n times

#include <iostream>
using namespace std;
int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
        return a;
    else
        return a * power(a, n - 1);
}
int main()
{
    cout << "Power of 5^3 is:" << power(5, 3);
}
//optimized version
//concept: 2^8=(2^2)^4=(2*2)^4
//if odd power 2^9=2*((2*2)^4)
/*
int power(int a,int n)
{
  if(n==0)
  return 1;
  else if(n%2==0)
  retuRN power(a*a,n/2);
  else
  return a*power(a*a,n/2);
  }*/