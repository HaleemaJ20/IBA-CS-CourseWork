#include <iostream>
using namespace std;

int sumA(int n)
{
    if (n == 0)
        return 0;

    return n + sumA(n - 1);
}

int sumB(int n, int acc = 0)
{
    if (n == 0)
        return acc;

    return sumB(n - 1, acc + n);
}

int factorialTail(int n, int acc = 1)
{
    if (n == 0)
        return acc;

    return factorialTail(n - 1, acc * n);
}

int main()
{
    cout << sumA(100000) << endl;
    cout << sumB(100000) << endl;
}

/* i) Version A is not tail-recursive because after the recursive call returns, addition still has to be performed.
      Version B is tail-recursive because the recursive call is the last operation; all computation is carried in the accumulator.

ii) Call stack trace
sumA(4)
Call	Pending
sumA(4)	4 + sumA(3)
sumA(3)	3 + sumA(2)
sumA(2)	2 + sumA(1)
sumA(1)	1 + sumA(0)
sumA(0)	return 0

Returns:
0 → 1 → 3 → 6 → 10

sumB(4,0)
Call	acc
sumB(4,0)	0
sumB(3,4)	4
sumB(2,7)	7
sumB(1,9)	9
sumB(0,10)	10

Direct return = 10*/

/* iv) Without compiler optimisation, both may crash due to stack overflow.
       This shows that C++ does not guarantee tail-call optimisation automatically.
       Even tail-recursive functions may still use full stack unless compiled with 
       optimisation flags (-O2, -O3).*/