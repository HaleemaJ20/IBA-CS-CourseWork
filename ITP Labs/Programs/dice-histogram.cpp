#include <iostream>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    constexpr int sides = 6;
    int d, n;

    cout << "Enter number of dices: ";
    cin >> d;

    cout << "Enter number of dice rolls: ";
    cin >> n;

    if (d < 0 || d > 100 || n < 0) {
        cout << "Invalid input. Number of dice must be between 0 and 100, and rolls must be non-negative.\n";
        return 1;
    }

    int freq[601] = {0}; 

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 6);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < d; ++j)
            sum += dist(gen);
        freq[sum]++;
    }
    for (int i = d; i <= 6 * d; ++i)
    {
        cout << setw(3) << i << ": ";
        for (int j = 0; j < freq[i]; ++j)
            cout << "*";
        cout << endl;
    }
    return 0;
}