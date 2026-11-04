#include <iostream>
#include <string>
using namespace std;

void toUpperCase(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = text[i] - 32;
    }
    cout << "Result: " << text << endl;
}

void toLowerCase(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = text[i] + 32;
    }
    cout << "Result: " << text << endl;
}

void reverseString(string text) {
    for (int i = text.length() - 1; i >= 0; i--) {
        cout << text[i];
    }
    cout << endl;
}

void countVowels(string text) {
    int count = 0;

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    cout << "Vowel count: " << count << endl;
}

int main() {

    void (*operations[4])(string) = {
        toUpperCase,
        toLowerCase,
        reverseString,
        countVowels
    };

    int choice;
    string text;

    while (true) {
        cout << "\nText Processor:\n";
        cout << "1. Uppercase\n";
        cout << "2. Lowercase\n";
        cout << "3. Reverse\n";
        cout << "4. Count Vowels\n";
        cout << "Enter choice (1-4) or 0 to exit: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter text: ";
        cin.ignore(); 
        getline(cin, text);

        operations[choice - 1](text);
    }

    return 0;
}