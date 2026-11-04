#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {

        //Print leading spaces
        for (int s = 1; s <= n - i; s++) {
            cout << "  ";            
        }

        //Print increasing numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        //Print decreasing numbers from i-1 down to 1
        for (int j = i - 1; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "\n";                
    }

    return 0;
}
