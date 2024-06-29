# Linked Lists in C++

## 1. Introduction to Linked Lists

A linked list is a linear data structure where each element is a separate object, known as a node. Each node contains two main components:

- **Data**: The value or data stored in the node.
- **Reference (or link)**: A pointer to the next node in the sequence.

Linked lists provide a flexible way of storing a collection of elements. They are different from arrays in that:

- Elements in a linked list are not stored in contiguous memory locations.
- Dynamic size: Linked lists can grow and shrink in size dynamically without the need for resizing or allocating new memory.

### Advantages of Linked Lists:

- Dynamic size: They can easily grow and shrink as needed.
- Efficient insertions/deletions: Adding or removing elements is more efficient compared to arrays, especially for large data sets.

### Disadvantages of Linked Lists:

- Memory usage: Linked lists use more memory due to the storage of pointers.
- Access time: Accessing elements is slower compared to arrays since elements are not stored contiguously.

## 2. Types of Linked Lists

### Singly Linked List

A singly linked list allows traversal in one direction, from the first node (head) to the last node (tail). Each node contains:

- **Data**: The value or data stored in the node.
- **Next**: A pointer to the next node in the sequence.

### Doubly Linked List

A doubly linked list allows traversal in both directions, from the first node to the last node and vice versa. Each node contains:

- **Data**: The value or data stored in the node.
- **Next**: A pointer to the next node in the sequence.
- **Prev**: A pointer to the previous node in the sequence.

### Circular Linked List

In a circular linked list, the last node points back to the first node, forming a circular structure. This can be either singly or doubly linked. Each node contains:

- **Data**: The value or data stored in the node.
- **Next**: A pointer to the next node in the sequence.

## 3. Operations on Linked Lists

### Insertion

Insertion can occur at various positions in a linked list:

- **At the beginning**: Adding a new node at the start of the list.
- **At the end**: Adding a new node at the end of the list.
- **At a specific position**: Adding a new node at a specified position within the list.

### Deletion

Deletion can target various nodes in a linked list:

- **First node**: Removing the node at the start of the list.
- **Specific node**: Removing a node that contains a specific value.
- **Last node**: Removing the node at the end of the list.

### Traversal

Traversal involves visiting each node in the list to perform a specific operation (e.g., printing the data). This can be done:

- **Forward traversal**: From the head to the tail.
- **Backward traversal** (in doubly linked lists): From the tail to the head.

### Search

Search involves finding a node with a specific value by traversing through the list.

## 4. Example Code in C++

### Singly Linked List

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by key
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    prev->next = temp->next;
    delete temp;
}

// Function to traverse the list
void traverseList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    traverseList(head);
    deleteNode(head, 20);
    traverseList(head);
    return 0;
}


### Singly Linked List

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by key
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;
    prev->next = temp->next;
    delete temp;
}

// Function to traverse the list
void traverseList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    traverseList(head);
    deleteNode(head, 20);
    traverseList(head);
    return 0;
}
```

### Doubly Linked List

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a new node at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Function to delete a node by key
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr) return;
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

// Function to traverse the list
void traverseList(Node* node) {
    Node* last;
    cout << "Traversal in forward direction: ";
    while (node != nullptr) {
        cout << node->data << " -> ";
        last = node;
        node = node->next;
    }
    cout << "nullptr" << endl;
    cout << "Traversal in reverse direction: ";
    while (last != nullptr) {
        cout << last->data << " -> ";
        last = last->prev;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    traverseList(head);
    deleteNode(head, 20);
    traverseList(head);
    return 0;
}
```

### Circular Linked List

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Function to delete a node by key
void deleteNode(Node*& head, int key) {
    if (head == nullptr) return;
    Node *temp = head, *prev = nullptr;
    while (temp->data != key) {
        if (temp->next == head) {
            cout << "Node not found." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == head && prev == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }
    if (temp == head) {
        prev = head;
        while (prev->next != head) {
            prev = prev->next;
        }
        head = temp->next;
        prev->next = head;
        delete temp;
    } else if (temp->next == head) {
        prev->next = head;
        delete temp;
    } else {
        prev->next = temp->next;
        delete temp;
    }
}

// Function to traverse the list
void traverseList(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    traverseList(head);
    deleteNode(head, 20);
    traverseList(head);
    return 0;
}
```
