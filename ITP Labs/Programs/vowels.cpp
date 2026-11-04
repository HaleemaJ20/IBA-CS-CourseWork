#include <iostream>
#include <string>
int count_vowels(std::string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
         || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            count++;
    }
    return count;
}

int main()
{
    std::string s;
    std::cout << "Enter a string:\n ";
    std::getline(std::cin, s); 

    std::cout << "Number of vowels: " << count_vowels(s);
    return 0;
}
