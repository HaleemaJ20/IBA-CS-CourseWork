#include <iostream>

// A custom string class (NOT std::string)
class string
{
public:
    // Constructor that takes a C-style string (char array ending with '\0')
    string(const char *c = "")
    {
        const char *ctemp = c;

        // Count length
        while (*ctemp != '\0')
        {
            ++m_len;
            ++ctemp;
        }

        // Handle length == 0 explicitly
        if (m_len > 0)
        {
            m_arr = new char[m_len];
            for (size_t i = 0; i < m_len; ++i)
            {
                m_arr[i] = c[i];
            }
        }
        else
        {
            m_arr = nullptr;
        }
    }

    // Destructor
    ~string()
    {
        delete[] m_arr;
        m_arr = nullptr;
        m_len = 0;
    }

    // Copy Constructor
    string(const string &other)
    {
        m_len = other.m_len;

        if (m_len > 0)
        {
            m_arr = new char[m_len];
            for (size_t i = 0; i < m_len; i++)
            {
                m_arr[i] = other.m_arr[i];
            }
        }
        else
        {
            m_arr = nullptr;
        }
    }

    // Copy assignment operator
    string &operator=(const string &other)
    {
        if (this == &other)
            return *this;

        delete[] m_arr;

        m_len = other.m_len;

        if (m_len > 0)
        {
            m_arr = new char[m_len];
            for (size_t i = 0; i < m_len; i++)
            {
                m_arr[i] = other.m_arr[i];
            }
        }
        else
        {
            m_arr = nullptr;
        }

        return *this;
    }

    // Subscript Operator
    char &operator[](size_t index)
    {
        return m_arr[index];
    }

    // Addition Operator
    string operator+(const string &other) const
    {
        string result;
        result.m_len = m_len + other.m_len;

        if (result.m_len > 0)
        {
            result.m_arr = new char[result.m_len];

            for (size_t i = 0; i < m_len; i++)
                result.m_arr[i] = m_arr[i];

            for (size_t i = 0; i < other.m_len; i++)
                result.m_arr[m_len + i] = other.m_arr[i];
        }
        else
        {
            result.m_arr = nullptr;
        }

        return result;
    }

    // Equality Operator
    bool operator==(const string &other) const
    {
        if (m_len != other.m_len)
            return false;

        for (size_t i = 0; i < m_len; i++)
        {
            if (m_arr[i] != other.m_arr[i])
                return false;
        }
        return true;
    }

    bool operator!=(const string &other) const
    {
        return !(*this == other);
    }

    size_t size() const
    {
        return m_len;
    }

    void print() const
    {
        for (size_t i = 0; i < m_len; ++i)
        {
            std::cout << m_arr[i];
        }
        std::cout << "\n";
    }

    bool isPalindrome() const
    {
        if (m_len <= 1)
            return true;

        for (size_t i = 0; i < m_len / 2; i++)
        {
            if (m_arr[i] != m_arr[m_len - 1 - i])
                return false;
        }
        return true;
    }

    char at(size_t index) const
    {
        if (index >= m_len)
        {
            std::cout << "Error: Index out of bounds!" << std::endl;
            return '\0';
        }
        return m_arr[index];
    }

    bool contains(char c) const
    {
        for (size_t i = 0; i < m_len; i++)
        {
            if (m_arr[i] == c)
                return true;
        }
        return false;
    }

    int find(char c) const
    {
        for (size_t i = 0; i < m_len; i++)
        {
            if (m_arr[i] == c)
                return i;
        }
        return -1;
    }

    void append(const string &other)
    {
        if (other.m_len == 0)
            return;

        size_t old_len = m_len;
        size_t new_len = m_len + other.m_len;

        char *new_arr = new char[new_len];

        for (size_t i = 0; i < old_len; i++)
            new_arr[i] = m_arr[i];

        for (size_t i = 0; i < other.m_len; i++)
            new_arr[old_len + i] = other.m_arr[i];

        delete[] m_arr;
        m_arr = new_arr;
        m_len = new_len;
    }

private:
    size_t m_len{0};
    char *m_arr{nullptr};
};

int main()

{
    string s1("Hello");
    string s2(" World");

    // Test 1: Copy constructor
    std::cout << "Test 1: Copy Constructor" << std::endl;
    string s3 = s1;

    std::cout << "Original s1: ";
    s1.print();
    std::cout << std::endl;

    std::cout << "Copy s3: ";
    s3.print();
    std::cout << std::endl;

    // Modify the copy and verify original is unchanged
    s3[0] = 'h';
    std::cout << "After modifying s3[0] to 'h':" << std::endl;

    std::cout << "Original s1: ";
    s1.print(); // Should still print: Hello
    std::cout << std::endl;

    std::cout << "Modified s3: ";
    s3.print(); // Should print: hello
    std::cout << std::endl
              << std::endl;

    // Test 2: Assignment operator
    std::cout << "Test 2: Assignment Operator" << std::endl;
    string s4("Initial");

    std::cout << "Before assignment, s4: ";
    s4.print();
    std::cout << std::endl;

    s4 = s2;
    std::cout << "After s4 = s2, s4: ";
    s4.print(); // Should print: World
    std::cout << std::endl
              << std::endl;

    // Test 3: Self-assignment
    std::cout << "Test 3: Self-assignment" << std::endl;
    s4 = s4;

    std::cout << "After s4 = s4, s4: ";
    s4.print();
    std::cout << std::endl
              << std::endl;

    // Test 4: [] operator
    std::cout << "Test 4: Subscript Operator []" << std::endl;
    std::cout << "s1[1] = " << s1[1] << std::endl;

    s1[0] = 'J';
    std::cout << "After s1[0] = 'J': ";
    s1.print(); // Should print: Jello
    std::cout << std::endl
              << std::endl;

    // Test 5: + operator
    std::cout << "Test 5: Concatenation Operator +" << std::endl;
    string s5("Hello");
    string s6(" World");
    string s7 = s5 + s6;

    std::cout << "s5: ";
    s5.print();
    std::cout << std::endl;

    std::cout << "s6: ";
    s6.print();
    std::cout << std::endl;

    std::cout << "s5 + s6 = ";
    s7.print(); // Should print: Hello World
    std::cout << std::endl
              << std::endl;

    // Test 6: == and != operators
    std::cout << "Test 6: Equality Operators == and !=" << std::endl;
    string s8("Hello");
    string s9("Hello");
    string s10("World");

    if (s8 == s9)
    {
        std::cout << "s8 and s9 are equal" << std::endl;
    }
    else
    {
        std::cout << "s8 and s9 are NOT equal" << std::endl;
    }

    if (s8 != s10)
    {
        std::cout << "s8 and s10 are NOT equal" << std::endl;
    }
    else
    {
        std::cout << "s8 and s10 are equal" << std::endl;
    }

    std::cout << std::endl;

    // Test 7: Existing methods from Lab 1
    std::cout << "Test 7: Lab 1 Methods Still Working" << std::endl;
    std::cout << "Size of s7: " << s7.size() << std::endl;
    std::cout << "s7 contains 'W': "
              << (s7.contains('W') ? "Yes" : "No") << std::endl;
    std::cout << "Index of 'W' in s7: " << s7.find('W') << std::endl;
    std::cout << "Is s8 palindrome? "
              << (s8.isPalindrome() ? "Yes" : "No") << std::endl;
    std::cout << "Character at index 1 in s8: " << s8.at(1) << std::endl;

    // Test 8: Append
    string s11("Hello");
    string s12(" There");
    s11.append(s12);

    std::cout << "After s11.append(s12): ";
    s11.print();
    std::cout << std::endl
              << std::endl;

    // Test 9: Chain operations
    std::cout << "Test 9: Chained Operations" << std::endl;
    string first("C");
    string second("++");
    string third(" Programming");
    string result = first + second + third;

    std::cout << "Result of chaining: ";
    result.print(); // Should print: C++ Programming
    std::cout << std::endl;

    return 0;
}
