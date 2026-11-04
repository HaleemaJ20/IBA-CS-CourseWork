#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int i = {1};
    int sum {0};

    while (i <= n/2){
        
        if (n % i == 0){
            sum += i;
        }
        i++;
    }

    if (sum == n){
        cout << n << " is a perfect number.";
    }

    else 
        cout << n << " is not a perfect number.";

return 0;
}