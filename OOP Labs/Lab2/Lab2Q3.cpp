#include <iostream>

class DynamicArray {
private:
    int* m_data;
    size_t m_size;
    size_t m_capacity;

    void resize(size_t new_capacity) {
        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }

        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

public:
    // Default constructor
    DynamicArray() {
        m_capacity = 10;
        m_size = 0;
        m_data = new int[m_capacity];
    }

    // Parameterized constructor
    DynamicArray(size_t initial_capacity) {
        m_capacity = initial_capacity;
        m_size = 0;
        m_data = new int[m_capacity];
    }

    // Copy constructor (deep copy)
    DynamicArray(const DynamicArray& other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        m_data = new int[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] m_data;
    }

    // Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        delete[] m_data;

        m_size = other.m_size;
        m_capacity = other.m_capacity;

        m_data = new int[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }

        return *this;
    }

    void push_back(int value) {
        if (m_size == m_capacity) {
            resize(m_capacity * 2);
        }

        m_data[m_size] = value;
        ++m_size;
    }

    void pop_back() {
        if (m_size > 0) {
            --m_size;
        }
    }

    int& operator[](size_t index) {
        return m_data[index];
    }

    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_capacity;
    }

    bool empty() const {
        return m_size == 0;
    }

    void clear() {
        m_size = 0;
    }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < m_size; ++i) {
            std::cout << m_data[i];
            if (i + 1 < m_size) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }
};

int main() {
    std::cout << "Test 1: Default Constructor and push_back" << std::endl;
    DynamicArray arr;

    for (int i = 1; i <= 15; ++i) {
        arr.push_back(i * 10);
        std::cout << "Added " << i * 10
                  << " | Size: " << arr.size()
                  << ", Capacity: " << arr.capacity()
                  << std::endl;
    }

    std::cout << "Array contents: ";
    arr.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test 2: Copy Constructor (Deep Copy)" << std::endl;
    DynamicArray arr2 = arr;
    arr2[0] = 999;

    std::cout << "Original array: ";
    arr.print();
    std::cout << std::endl;

    std::cout << "Copied array (modified): ";
    arr2.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test 3: Assignment Operator" << std::endl;
    DynamicArray arr3;
    arr3.push_back(1);
    arr3.push_back(2);

    std::cout << "arr3 before assignment: ";
    arr3.print();
    std::cout << std::endl;

    arr3 = arr;
    std::cout << "arr3 after assignment: ";
    arr3.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test 4: Subscript Operator []" << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "arr[5] = " << arr[5] << std::endl;
    arr[5] = 777;

    std::cout << "After arr[5] = 777: ";
    arr.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test 5: pop_back" << std::endl;
    arr.pop_back();
    arr.pop_back();

    std::cout << "After two pop_back() calls: ";
    arr.print();
    std::cout << " | Size: " << arr.size() << std::endl << std::endl;

    std::cout << "Test 6: empty() and clear()" << std::endl;
    std::cout << "Is arr empty? " << (arr.empty() ? "Yes" : "No") << std::endl;

    arr.clear();
    std::cout << "After clear(), size: " << arr.size()
              << ", capacity: " << arr.capacity() << std::endl;

    std::cout << "Is arr empty now? " << (arr.empty() ? "Yes" : "No") << std::endl << std::endl;

    std::cout << "Test 7: Parameterized Constructor" << std::endl;
    DynamicArray arr4(5);

    std::cout << "arr4 initial capacity: " << arr4.capacity() << std::endl;

    for (int i = 1; i <= 8; ++i) {
        arr4.push_back(i);
    }

    std::cout << "After adding 8 elements, capacity: " << arr4.capacity() << std::endl;
    std::cout << "arr4: ";
    arr4.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test 8: Self-assignment" << std::endl;
    arr4 = arr4;

    std::cout << "After self-assignment, arr4: ";
    arr4.print();
    std::cout << std::endl;

    return 0;
}
