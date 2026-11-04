#include <iostream>

// A custom string class (NOT std::string)
class string {
public:

    // Constructor that takes a C-style string (char array ending with '\0')
    string(const char* c) {

        // Temporary pointer to traverse the input string
        const char* ctemp = c;

        // Count length of the string manually
        while(*ctemp != '\0') {
            ++m_len;
            ++ctemp;
        }

        // Allocate dynamic memory to store characters
        m_arr = new char[m_len];

        // Copy characters from input string into our array
        for (size_t i = 0; i < m_len; ++i) {
            m_arr[i] = c[i];
        }
    }

    // Default constructor (creates an empty string of length 1)
    string(){
        m_len = 1;          // Set length to 1
        m_arr = new char;   // Allocate memory for 1 character
    }

    // Returns the length of the string
    size_t size() {
        return m_len;
    }

    // Prints the stored characters to the console
    void print() {
        for (size_t i = 0; i < m_len; ++i) {
            std::cout << m_arr[i];
        }
        std::cout << "\n";
    }

    bool isPalindrome(){
        if (m_len == 0 || m_len == 1)
        return true;
        size_t left = 0, right = m_len - 1;
        while (left < right){
            if (m_arr[left] != m_arr[right])
            return false;
            left++;
            right--;
        }
        return true;
    }

    char at(size_t index){
        if (index >= m_len || index < 0){
            std:: cout << "Invalid Index";
            return '\0';
        }
        return m_arr[index];
    }

    bool contains(char c){
        for (size_t i = 0; i < m_len; i++){
             if (m_arr[i] == c)
             return true;
        }
        return false;
    }

    int find (char c){
        for (size_t i = 0; i < m_len; i++){
             if (m_arr[i] == c)
             return i;
        }
        return -1;
    }

    void append(const string& other){
        if (other.m_len == 0) 
        return;
        char* newArr = new char[m_len + other.m_len];
        for (size_t i = 0; i < m_len; i++){
            newArr[i] = m_arr[i];
        }
        for (size_t i = 0; i < other.m_len; i++){
            newArr[m_len + i] = other.m_arr[i];
        }
        
        delete[] m_arr;
        m_arr = newArr;
        m_len += other.m_len;
    }

private:
    size_t m_len{0};     // Stores number of characters in the string
    char* m_arr{nullptr}; // Pointer to dynamically allocated character array
};

int main() {
    string s1 ("level");
    std:: cout << "String1: ";
    s1.print();
    std:: cout << "Is string1 a palindrome? " << (s1.isPalindrome() ? "yes" : "no") << "\n";

    string s2 ("Hello");
    std:: cout << "String2: ";
    s2.print();
    std:: cout << "Character at index 1 in string 2 is: " << s2.at(1) << '\n';
    std:: cout << "Character at index 10 in string 2 is: " << s2.at(10) << '\n';

    std:: cout << "String2 contains 'e'? " << (s2.contains('e') ? "yes" : "no") << "\n";
    std:: cout << "String2 contains 'j'? " << (s2.contains('j') ? "yes" : "no") << "\n";

    std:: cout << "In string2 'l' is at index: " << s2.find('l') << '\n';
    std:: cout << "In string2 'c' is at index: " << s2.find('c') << '\n';

    string s3(" World");
    std:: cout << "String3: ";
    s2.append(s3);
    s2.print();

    return 0;
}
