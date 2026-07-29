// Implement basic stack operations using linkedlist i.e.
// push
// pop
// peek
// display



//Solution :
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Top pointer
Node* top = NULL;

// Push operation
void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed into stack.\n";
}

// Pop operation
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return;
    }

    Node* temp = top;
    cout << top->data << " popped from stack.\n";
    top = top->next;
    delete temp;
}

// Peek operation
void peek() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element: " << top->data << endl;
    }
}

// Display operation
void display() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements (Top to Bottom): ";
    Node* temp = top;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Check if stack is empty
void isEmpty() {
    if (top == NULL)
        cout << "Stack is empty.\n";
    else
        cout << "Stack is not empty.\n";
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}