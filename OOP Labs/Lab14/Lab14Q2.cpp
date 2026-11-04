/*(a) The naive call count grows exponentially.
Because each call makes two more recursive calls, so total calls increase very rapidly as n increases.

(b) Memoised calls grow much more slowly because previously computed Fibonacci values are stored in memory.
If a value is already calculated, it is reused directly instead of recomputing recursive calls.
This makes the growth approximately linear.*/

#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace chrono;

long long callsNaive = 0;
long long callsMemo = 0;
unordered_map<int, long long> memo;

long long fibNaive(int n)
{
    ++callsNaive;
    if (n <= 1)
        return n;

    return fibNaive(n - 1) + fibNaive(n - 2);
}

long long fibMemo(int n)
{
    ++callsMemo;

    if (n <= 1)
        return n;

    if (memo.count(n))
        return memo[n];

    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

int main()
{
    cout << "n\tNaive calls\tMemo calls\tNaive time(ms)\tMemo time(ms)\n";

    int values[] = {10, 20, 30, 35, 40};

    for (int n : values)
    {
        callsNaive = 0;
        callsMemo = 0;
        memo.clear();

        auto start1 = high_resolution_clock::now();
        fibNaive(n);
        auto end1 = high_resolution_clock::now();

        auto start2 = high_resolution_clock::now();
        fibMemo(n);
        auto end2 = high_resolution_clock::now();

        auto naiveTime = duration_cast<milliseconds>(end1 - start1).count();
        auto memoTime = duration_cast<milliseconds>(end2 - start2).count();

        cout << n << "\t" << callsNaive << "\t\t" << callsMemo
             << "\t\t" << naiveTime << "\t\t" << memoTime << "\n";
    }

    return 0;
}