#include <iostream>
#include <string>
using namespace std;

string removeChar(const string& s, char c, int i = 0)
{
    if (i == s.length())
        return "";

    if (s[i] == c)
        return removeChar(s, c, i + 1);

    return s[i] + removeChar(s, c, i + 1);
}

int countChar(const string& s, char ch, int i = 0)
{
    if (i == s.length())
        return 0;

    if (s[i] == ch)
        return 1 + countChar(s, ch, i + 1);

    return countChar(s, ch, i + 1);
}

bool checkChars(const string& a, const string& b, int i = 0)
{
    if (i == a.length())
        return true;

    if (countChar(a, a[i]) != countChar(b, a[i]))
        return false;

    return checkChars(a, b, i + 1);
}

bool isAnagram(const string& a, const string& b)
{
    if (a.length() != b.length())
        return false;

    return checkChars(a, b);
}

int countVowels(const string& s, int i = 0)
{
    if (i == s.length())
        return 0;

    char ch = tolower(s[i]);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1 + countVowels(s, i + 1);

    return countVowels(s, i + 1);
}

string toBinary(int n)
{
    if (n == 0)
        return "0";

    if (n == 1)
        return "1";

    return toBinary(n / 2) + char((n % 2) + '0');
}

int main()
{
    cout << "removeChar:\n";
    cout << removeChar("banana", 'a') << endl;
    cout << removeChar("apple", 'p') << endl;
    cout << removeChar("hello", 'l') << endl;

    cout << "\nisAnagram:\n";
    cout << isAnagram("listen", "silent") << endl;
    cout << isAnagram("cat", "act") << endl;
    cout << isAnagram("dog", "gods") << endl;

    cout << "\ncountVowels:\n";
    cout << countVowels("hello") << endl;
    cout << countVowels("education") << endl;
    cout << countVowels("sky") << endl;

    cout << "\ntoBinary:\n";
    cout << toBinary(13) << endl;
    cout << toBinary(7) << endl;
    cout << toBinary(20) << endl;

    return 0;
}