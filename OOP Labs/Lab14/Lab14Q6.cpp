/*iii) 
T(n) = T(n−1) + 1 + T(n−1)
T(n) = 2T(n−1) + 1

T(n) = 2^n − 1*/

#include <iostream>
using namespace std;

int moves = 0;

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Move disc 1 from " << from << " to " << to << endl;
        moves++;
        return;
    }

    hanoi(n - 1, from, aux, to);

    cout << "Move disc " << n << " from " << from << " to " << to << endl;
    moves++;

    hanoi(n - 1, aux, to, from);
}

int main()
{
    cout << "Moves for n = 3:\n";
    moves = 0;
    hanoi(3, 'A', 'C', 'B');

    return 0;
}

/*   n       Total moves 
     1            1 
     2            3 
     3            7 
     4           15 
     5           31 
*/