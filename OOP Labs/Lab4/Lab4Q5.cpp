#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(frontIndex + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        frontIndex = 0;
        rearIndex = count;
    }

public:
    Queue(int cap = 4) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (count == capacity) {
            resize();
        }
        arr[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() const {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool empty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    int getCapacity() const {
        return capacity;
    }
};

int main() {
    Queue q;
    int customersServed = 0;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);

    cout << "Serving: " << q.front() << endl;
    q.dequeue();
    customersServed++;

    cout << "Serving: " << q.front() << endl;
    q.dequeue();
    customersServed++;

    cout << "Total customers served: " << customersServed << endl;

    return 0;
}
