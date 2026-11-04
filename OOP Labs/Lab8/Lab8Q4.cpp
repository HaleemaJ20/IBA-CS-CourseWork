#include <iostream>
using namespace std;

//SimpleVector
template <typename T>
class SimpleVector {
private:
    T* data;
    int size;
    int capacity;

public:
    SimpleVector() {
        size = 0;
        capacity = 2;
        data = new T[capacity];
    }

    ~SimpleVector() {
        delete[] data;
    }

    void push_back(T val) {
        if (size == capacity) {
            capacity = capacity * 2;
            T* newData = new T[capacity];

            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

        data[size] = val;
        size++;
    }

    T at(int index) {
        return data[index];   
    }

    int getSize() {
        return size;
    }
};

//SimpleList
template <typename T>
class SimpleList {
public:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    int size;

public:
    SimpleList() {
        head = nullptr;
        size = 0;
    }

    ~SimpleList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(T val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        size++;
    }

    Node* getHead() {
        return head;
    }

    int getSize() {
        return size;
    }
};

//findMin 

// for vector
template <typename T>
T findMin(SimpleVector<T>& v) {
    T min = v.at(0);

    for (int i = 1; i < v.getSize(); i++) {
        if (v.at(i) < min) {
            min = v.at(i);
        }
    }

    return min;
}

// for list
template <typename T>
T findMin(SimpleList<T>& l) {
    typename SimpleList<T>::Node* temp = l.getHead();
    T min = temp->data;

    while (temp != nullptr) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }

    return min;
}

//displayAll

// for vector
template <typename T>
void displayAll(SimpleVector<T>& v) {
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

// for list
template <typename T>
void displayAll(SimpleList<T>& l) {
    typename SimpleList<T>::Node* temp = l.getHead();

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    SimpleVector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(9);

    cout << "Vector: ";
    displayAll(v);

    cout << "Min (Vector): " << findMin(v) << endl;

    SimpleList<int> l;
    l.insert(5);
    l.insert(2);
    l.insert(9);

    cout << "List: ";
    displayAll(l);

    cout << "Min (List): " << findMin(l) << endl;

    return 0;
}