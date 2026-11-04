#include <iostream>
#include <string>
using namespace std;
int main()
{
    int amount;
    cout << "Enter an amount in figures (-999,999 to 999,999): ";
    cin >> amount;

    if (amount == 0){
        cout << "In Words: Zero\n";
        return 0;
    }
    
    cout << "In words: ";
    if (amount < 0){
        cout << "negative ";
        amount = -amount;
    }

    int thousands = amount / 1000;
    int rest = amount % 1000;

    //print thousands
    if (thousands > 0){
        int h = thousands / 100;           //h = hundreds
        int t = (thousands % 100) / 10;    //t = tens  
        int o = thousands % 10;            //o = ones
        
        //hundreds
        if (h > 0){
            if (h == 1) cout << "one ";
            else if (h == 2) cout << "two ";
            else if (h == 3) cout << "three ";
            else if (h == 4) cout << "four ";
            else if (h == 5) cout << "five ";
            else if (h == 6) cout << "six ";
            else if (h == 7) cout << "seven ";
            else if (h == 8) cout << "eight ";
            else if (h == 9) cout << "nine ";
            
            cout << "hundred";
            if (thousands % 100) cout << " ";
        }

        int tens_ones = thousands % 100;
        if (tens_ones > 0 && tens_ones < 20){
            if (tens_ones == 1) cout << "one ";
            else if (tens_ones == 2) cout << "two ";
            else if (tens_ones == 3) cout << "three ";
            else if (tens_ones == 4) cout << "four ";
            else if (tens_ones == 5) cout << "five ";
            else if (tens_ones == 6) cout << "six ";
            else if (tens_ones == 7) cout << "seven ";
            else if (tens_ones == 8) cout << "eight ";
            else if (tens_ones == 9) cout << "nine ";
            else if (tens_ones == 10) cout << "ten ";
            else if (tens_ones == 11) cout << "eleven ";
            else if (tens_ones == 12) cout << "twelve ";
            else if (tens_ones == 13) cout << "thirteen ";
            else if (tens_ones == 14) cout << "fourteen ";
            else if (tens_ones == 15) cout << "fifteen ";
            else if (tens_ones == 16) cout << "sixteen ";
            else if (tens_ones == 17) cout << "seventeen ";
            else if (tens_ones == 18) cout << "eighteen ";
            else if (tens_ones == 19) cout << "nineteen ";
            else if (tens_ones == 20) cout << "twenty ";
        }
        else if (tens_ones >= 20){
            int tens = tens_ones / 10;
            int ones = tens_ones % 10;
            if (tens == 3) cout << "thirty";
            else if (tens == 4) cout << "forty";
            else if (tens == 5) cout << "fifty";
            else if (tens == 6) cout << "sixty";
            else if (tens == 7) cout << "seventy";
            else if (tens == 8) cout << "eighty";
            else if (tens == 9) cout << "ninety";
            if (ones > 0){
                cout << " ";
                if (ones == 1) cout << "one";
                else if (ones == 2) cout << "two";
                else if (ones == 3) cout << "three";
                else if (ones == 4) cout << "four";
                else if (ones == 5) cout << "five";
                else if (ones == 6) cout << "six";
                else if (ones == 7) cout << "seven";
                else if (ones == 8) cout << "eight";
                else if (ones == 9) cout << "nine";
            }
        }
        cout << " thousand";
        if (rest) cout << " ";
    }
    //print remainder
    if (rest > 0){
        int h = rest / 100;
        int t = (rest % 100) / 10;
        int o = rest % 10;

         if (h > 0) {
            if (h == 1) cout << "one ";
            else if (h == 2) cout << "two ";
            else if (h == 3) cout << "three ";
            else if (h == 4) cout << "four ";
            else if (h == 5) cout << "five ";
            else if (h == 6) cout << "six ";
            else if (h == 7) cout << "seven ";
            else if (h == 8) cout << "eight ";
            else if (h == 9) cout << "nine ";
            cout <<"hundred";
            if (rest % 100) cout << " ";
        }

        int tens_ones = rest % 100;
        if (tens_ones > 0 && tens_ones < 20) {
            if (tens_ones == 1) cout << "one ";
            else if (tens_ones == 2) cout << "two ";
            else if (tens_ones == 3) cout << "three ";
            else if (tens_ones == 4) cout << "four ";
            else if (tens_ones == 5) cout << "five ";
            else if (tens_ones == 6) cout << "six ";
            else if (tens_ones == 7) cout << "seven ";
            else if (tens_ones == 8) cout << "eight ";
            else if (tens_ones == 9) cout << "nine ";
            else if (tens_ones == 10) cout << "ten ";
            else if (tens_ones == 11) cout << "eleven ";
            else if (tens_ones == 12) cout << "twelve ";
            else if (tens_ones == 13) cout << "thirteen ";
            else if (tens_ones == 14) cout << "fourteen ";
            else if (tens_ones == 15) cout << "fifteen ";
            else if (tens_ones == 16) cout << "sixteen ";
            else if (tens_ones == 17) cout << "seventeen ";
            else if (tens_ones == 18) cout << "eighteen ";
            else if (tens_ones == 19) cout << "nineteen ";
        }

        else if (tens_ones >= 20) {
            int tens = tens_ones / 10;
            int ones = tens_ones % 10;
            if (tens == 2) cout<<"twenty";
            else if (tens == 3) cout<<"thirty";
            else if (tens == 4) cout<<"forty";
            else if (tens == 5) cout<<"fifty";
            else if (tens == 6) cout<<"sixty";
            else if (tens == 7) cout<<"seventy";
            else if (tens == 8) cout<<"eighty";
            else if (tens == 9) cout<<"ninety";
            if (ones > 0) {
                cout << " ";
                if (ones == 1) cout<<"one";
                else if (ones == 2) cout<<"two";
                else if (ones == 3) cout<<"three";
                else if (ones == 4) cout<<"four";
                else if (ones == 5) cout<<"five";
                else if (ones == 6) cout<<"six";
                else if (ones == 7) cout<<"seven";
                else if (ones == 8) cout<<"eight";
                else if (ones == 9) cout<<"nine";
            }
        }
    }

    cout << "\n";
    return 0;
}