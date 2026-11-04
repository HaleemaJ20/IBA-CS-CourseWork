#include <iostream>

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
    Queue(int cap = 4)
        : capacity(cap), frontIndex(0), rearIndex(0), count(0) {
        arr = new int[capacity];
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
        if (empty())
            return;

        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() const {
        if (empty())
            return -1;
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
    Queue q(2);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front: " << q.front() << std::endl;
    q.dequeue();
    std::cout << "Front after dequeue: " << q.front() << std::endl;
    std::cout << "Size: " << q.size() << std::endl;
    std::cout << "Capacity: " << q.getCapacity() << std::endl;
    return 0;
}
