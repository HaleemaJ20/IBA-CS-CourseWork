
#include <iostream>
#include <string>
using namespace std;

// Task structure
struct Node {
    int TaskID;
    string name;
    int duration; // in minutes
    Node* next;
};

// Remove the first node
void pop_front(Node* &head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    temp->next = nullptr; // disconnect
    delete temp;
}

// Add a node at the end
void push_back(Node* &head, Node* newNode) {
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Process tasks for 10 minutes per iteration
void processTasks(Node* head) {
    if (!head) return;

    int iteration = 1;

    while (head != nullptr) {
        cout << "Iteration " << iteration << ":\n";

        int nodeCount = 0;
        Node* temp = head;
        while(temp) { nodeCount++; temp = temp->next; } // count tasks

        int tasksProcessed = 0;
        while (tasksProcessed < nodeCount) {
            Node* current = head;  // always process first task

            if (current->duration <= 10) {
                cout << "Processing Task " << current->TaskID
                     << ": \"" << current->name
                     << "\" - Completed\n";
                pop_front(head); // remove completed task
            } else {
                current->duration -= 10;
                cout << "Processing Task " << current->TaskID
                     << ": \"" << current->name
                     << "\" - Remaining Duration: "
                     << current->duration << " minutes\n";
                // move task to end
                pop_front(head);
                push_back(head, current);
            }

            tasksProcessed++;
        }

        iteration++;
    }

    cout << "done!\n";
}

// Example usage
int main() {
    Node* head = nullptr;

    // Creating example tasks
    Node* t1 = new Node{1, "Compile Code", 15, nullptr};
    Node* t2 = new Node{2, "Test Software", 25, nullptr};
    Node* t3 = new Node{3, "Write Documentation", 5, nullptr};

    push_back(head, t1);
    push_back(head, t2);
    push_back(head, t3);

    // Process all tasks
    processTasks(head);

    return 0;
}
