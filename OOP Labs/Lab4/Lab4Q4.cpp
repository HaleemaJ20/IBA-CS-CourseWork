#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;

        Node(int val, Node* nxt = nullptr) {
            data = val;
            next = nxt;
        }
    };

    Node* topNode;
    int count;

public:
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    void push(int value){
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        count++;
    }

    void pop() {
        if (empty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    int top() const {
        if (empty()) {
            cout << "Stack is empty!\n";
            return -1; 
        }
        return topNode->data;
    }

    bool empty() const {
        return topNode == nullptr;
    }

    int size() const {
        return count;
    }
};

bool isBalanced(const string& expr) {
    Stack s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);   // char → int
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty())
                return false;

            char topChar = s.top(); // int → char
            s.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
                return false;
        }
    }

    return s.empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";

    cout << isBalanced(expr1) << endl; // 1
    cout << isBalanced(expr2) << endl; // 0

    return 0;
}
