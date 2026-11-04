#include <iostream>

// A custom string class (NOT std::string)
class string {
public:

    // Constructor that takes a C-style string (char array ending with '\0')
    string(const char* c) {

        const char* ctemp = c;

        while (*ctemp != '\0') {
            ++m_len;
            ++ctemp;
        }

        if (m_len > 0) {
            m_arr = new char[m_len];
            for (size_t i = 0; i < m_len; ++i) {
                m_arr[i] = c[i];
            }
        }
    }

    // Default constructor
    string() {
        m_len = 0;
        m_arr = nullptr;
    }

    string(const string& other) {
        std::cout << "Copy Constructor called" << std::endl;

        m_len = other.m_len;

        if (m_len > 0) {
            m_arr = new char[m_len];
            for (size_t i = 0; i < m_len; ++i) {
                m_arr[i] = other.m_arr[i];
            }
        } else {
            m_arr = nullptr;
        }
    }

    string& operator=(const string& other) {
        std::cout << "Copy Assignment called" << std::endl;

        if (this == &other)
            return *this;

        delete[] m_arr;

        m_len = other.m_len;

        if (m_len > 0) {
            m_arr = new char[m_len];
            for (size_t i = 0; i < m_len; ++i) {
                m_arr[i] = other.m_arr[i];
            }
        } else {
            m_arr = nullptr;
        }

        return *this;
    }

    string(string&& other) noexcept {
        std::cout << "Move Constructor called" << std::endl;

        m_len = other.m_len;
        m_arr = other.m_arr;

        other.m_len = 0;
        other.m_arr = nullptr;
    }

    string& operator=(string&& other) noexcept {
        std::cout << "Move Assignment called" << std::endl;

        if (this == &other)
            return *this;

        delete[] m_arr;

        m_len = other.m_len;
        m_arr = other.m_arr;

        other.m_len = 0;
        other.m_arr = nullptr;

        return *this;
    }

    // Destructor
    ~string() {
        delete[] m_arr;
    }

    size_t size() {
        return m_len;
    }

    void print() {
        for (size_t i = 0; i < m_len; ++i) {
            std::cout << m_arr[i];
        }
        std::cout << std::endl;
    }

private:
    size_t m_len{0};
    char* m_arr{nullptr};
};

string makeString() {
    string temp("Hello");
    return std::move(temp);
}

int main() {
    string s1("World");
    string s2 = s1;            // Copy constructor
    string s3 = makeString();  // Move constructor

    string s4("Test");
    s4 = s1;                   // Copy assignment
    s4 = makeString();         // Move assignment

    return 0;
}