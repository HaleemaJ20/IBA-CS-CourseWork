#include <iostream>
using namespace std;

class MinStack {
private:
    int* values;
    int* mins;
    int topIndex;
    int capacity;

public:
    MinStack() {
        capacity = 100;
        values = new int[capacity];
        mins = new int[capacity];
        topIndex = -1;
    }

    ~MinStack() {
        delete[] values;
        delete[] mins;
    }

    void push(int x) {
        topIndex++;
        values[topIndex] = x;

        if (topIndex == 0 || x < mins[topIndex - 1]) {
            mins[topIndex] = x;
        } else {
            mins[topIndex] = mins[topIndex - 1];
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }

    int top() const {
        if (topIndex >= 0) {
            return values[topIndex];
        }
        return -1;
    }

    int getMin() const {
        if (topIndex >= 0) {
            return mins[topIndex];
        }
        return -1;
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(2);
    ms.push(8);
    cout << ms.getMin() << endl; // 2
    ms.pop();
    cout << ms.getMin() << endl; // 2
    ms.pop();
    cout << ms.getMin() << endl; // 5
    return 0;
}
