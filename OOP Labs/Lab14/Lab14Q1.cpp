/*a) If negative input is not handled, the function keeps calling itself with -2, -3, -4 
and never reaches the base case n == 0, causing stack overflow and program crash.*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << "Entering factorial(" << n << ")\n";

    if (n < 0)      //b part
        return -1; 

    int result;

    if (n == 0)
        result = 1;
    else
        result = n * factorial(n - 1);

    cout << "Leaving factorial(" << n << ") = " << result << "\n";

    return result;
}

int main()
{
    cout << "factorial(-1) = " << factorial(-1) << "\n";
    return 0;
}

/*Manual trace for factorial(5)
Step	Action	                    Stack (top → bottom)	                                    Pending return value
1	    call factorial(5)	        fact(5)	                                                    5 × factorial(4)
2	    call factorial(4)	        fact(4), fact(5)	                                        4 × factorial(3)
3	    call factorial(3)	        fact(3), fact(4), fact(5)	                                3 × factorial(2)
4	    call factorial(2)	        fact(2), fact(3), fact(4), fact(5)	                        2 × factorial(1)
5	    call factorial(1)	        fact(1), fact(2), fact(3), fact(4), fact(5)	                1 × factorial(0)
6	    call factorial(0)	        fact(0), fact(1), fact(2), fact(3), fact(4), fact(5)	    returns 1
7	    return from factorial(1)	fact(1), fact(2), fact(3), fact(4), fact(5)	                1 × 1 = 1
8	    return from factorial(2)	fact(2), fact(3), fact(4), fact(5)	                        2 × 1 = 2
9	    return from factorial(3)	fact(3), fact(4), fact(5)	                                3 × 2 = 6
10	    return from factorial(4)	fact(4), fact(5)	                                        4 × 6 = 24
11	    return from factorial(5)	fact(5)	                                                    5 × 24 = 120  */