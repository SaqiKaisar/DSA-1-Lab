#include <iostream>
using namespace std;

// Structure for Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Global head pointer
Node* head = NULL;

// ------------------------- INSERTION -------------------------

// CASE 1: Insert at the Beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    // If list is not empty, update the old head's prev pointer
    if (head != NULL) {
        head->prev = newNode;
    }
    // Update head to the new node
    head = newNode;
    cout << "Inserted " << val << " at the beginning." << endl;
}

// CASE 2: Insert at the End
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    // If list is empty, the new node becomes the head
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        cout << "Inserted " << val << " at the end (first node)." << endl;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node after the last node
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Inserted " << val << " at the end." << endl;
}

// CASE 3: Insert After a Particular Node (Target Value)
void insertAfterNode(int targetVal, int val) {
    Node* temp = head;
    
    // Find the node with the target value
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }

    // If target node is not found
    if (temp == NULL) {
        cout << "Target node " << targetVal << " not found!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    // Link new node's next and prev
    newNode->next = temp->next;
    newNode->prev = temp;

    // If temp is not the last node, update the next node's prev pointer
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    // Update target node's next pointer
    temp->next = newNode;
    cout << "Inserted " << val << " after " << targetVal << "." << endl;
}

// ------------------------- DELETION -------------------------

// CASE 1: Delete at the Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next; // Shift head to the next node

    // If the list has more than one node, set the new head's prev to NULL
    if (head != NULL) {
        head->prev = NULL;
    }

    cout << "Deleted " << temp->data << " from the beginning." << endl;
    delete temp;
}

// CASE 2: Delete at the End
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;

    // If there is only one node
    if (temp->next == NULL) {
        head = NULL;
        cout << "Deleted " << temp->data << " from the end." << endl;
        delete temp;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Disconnect the last node from the list
    temp->prev->next = NULL;
    cout << "Deleted " << temp->data << " from the end." << endl;
    delete temp;
}

// CASE 3: Delete After a Particular Node
void deleteAfterNode(int targetVal) {
    Node* temp = head;

    // Find the target node
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }

    // If target node not found or it is the last node (nothing after it)
    if (temp == NULL || temp->next == NULL) {
        cout << "Cannot delete after " << targetVal << ". Node not found or is the last node." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;

    // Link target node to the node AFTER the one being deleted
    temp->next = nodeToDelete->next;

    // If the node being deleted is not the last node, update the next node's prev
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }

    cout << "Deleted " << nodeToDelete->data << " which was after " << targetVal << "." << endl;
    delete nodeToDelete;
}

// ------------------------- DISPLAY & SEARCH -------------------------

void display() {
    Node* temp = head;
    cout << "DLL: NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void search(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found " << key << " at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << key << " not found." << endl;
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAfterNode(20, 25);
    display();
    
    deleteAtBeginning();
    display();
    
    deleteAfterNode(20);
    display();
    
    deleteAtEnd();
    display();

    return 0;
}