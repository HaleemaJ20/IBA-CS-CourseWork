#include <iostream>
#include <vector>
using namespace std;

struct Packet {
    int size;
    string protocol;
    long timestamp;
};

template <typename T>
class RingBuffer {
private:
    vector<T> buffer;
    int capacity;
    int head;   
    int count;  

public:
    RingBuffer(int cap) : capacity(cap), head(0), count(0) {
        buffer.resize(capacity);
    }

    void push(T item) {
        buffer[head] = item;
        head = (head + 1) % capacity;

        if (count < capacity)
            count++;
    }

    class Iterator {
    private:
        RingBuffer* rb;
        int index;
        int traversed;

    public:
        Iterator(RingBuffer* r, int i, int t)
            : rb(r), index(i), traversed(t) {}

        T& operator*() {
            return rb->buffer[index];
        }

        Iterator& operator++() {
            index = (index + 1) % rb->capacity;
            traversed++;
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return traversed != other.traversed;
        }
    };

    Iterator begin() {
        int start = (head - count + capacity) % capacity;
        return Iterator(this, start, 0);
    }

    Iterator end() {
        return Iterator(this, 0, count);
    }
};

template <typename Iter, typename Predicate>
int longestConsecutiveStreak(Iter first, Iter last, Predicate pred) {
    int maxStreak = 0;
    int current = 0;

    for (auto it = first; it != last; ++it) {
        if (pred(*it)) {
            current++;
            if (current > maxStreak)
                maxStreak = current;
        } else {
            current = 0;
        }
    }

    return maxStreak;
}

int main() {

    RingBuffer<Packet> rb(10);

    // Mock packets
    vector<string> protocols = {"TCP", "UDP", "TCP", "TCP", "ICMP",
                               "TCP", "TCP", "TCP", "UDP", "TCP"};

    for (int i = 0; i < protocols.size(); i++) {
        rb.push({100 + i, protocols[i], i});
    }

    // Predicate: check TCP
    auto isTCP = [](const Packet& p) {
        return p.protocol == "TCP";
    };

    int result = longestConsecutiveStreak(rb.begin(), rb.end(), isTCP);

    cout << "Longest TCP streak: " << result << endl;

    return 0;
}