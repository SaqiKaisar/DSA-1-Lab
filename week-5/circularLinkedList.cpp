#include <iostream>
using namespace std;

// Structure for Circular Linked List Node
struct Node {
    int data;
    Node* next;
};

// Global last pointer
Node* last = NULL;

// ------------------------- INSERTION -------------------------

// CASE 1: Insert at the Beginning
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    // If the list is empty
    if (last == NULL) {
        last = newNode;
        last->next = last; // Points to itself
    } else {
        // New node points to the current head (which is last->next)
        newNode->next = last->next;
        // Last node points to the new node (making it the new head)
        last->next = newNode;
    }
    cout << "Inserted " << val << " at the beginning." << endl;
}

// CASE 2: Insert at the End
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    // If the list is empty
    if (last == NULL) {
        last = newNode;
        last->next = last; 
    } else {
        // Insert exactly like we do at the beginning
        newNode->next = last->next;
        last->next = newNode;
        
        // The ONLY difference from insertAtBeginning: we shift the 'last' pointer!
        last = newNode;
    }
    cout << "Inserted " << val << " at the end." << endl;
}

// CASE 3: Insert After a Particular Node
void insertAfterNode(int targetVal, int val) {
    if (last == NULL) return;

    // Start at the head
    Node* temp = last->next;
    
    do {
        if (temp->data == targetVal) {
            Node* newNode = new Node();
            newNode->data = val;
            
            // Link new node between temp and temp->next
            newNode->next = temp->next;
            temp->next = newNode;
            
            // If the target node was the last node, update the last pointer
            if (temp == last) {
                last = newNode;
            }
            
            cout << "Inserted " << val << " after " << targetVal << "." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != last->next); // Stop if we loop back to head

    cout << "Target node " << targetVal << " not found!" << endl;
}

// ------------------------- DELETION -------------------------

// CASE 1: Delete at the Beginning
void deleteAtBeginning() {
    if (last == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = last->next; // The head node

    // If there is only one node
    if (last->next == last) {
        last = NULL;
    } else {
        // Link last node to the second node
        last->next = temp->next;
    }

    cout << "Deleted " << temp->data << " from the beginning." << endl;
    delete temp;
}

// CASE 2: Delete at the End
void deleteAtEnd() {
    if (last == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = last->next; // Start at head

    // If there is only one node
    if (last->next == last) {
        cout << "Deleted " << last->data << " from the end." << endl;
        delete last;
        last = NULL;
        return;
    }

    // Traverse to find the second-to-last node
    while (temp->next != last) {
        temp = temp->next;
    }

    // temp is now the second-to-last node. Link it to head.
    temp->next = last->next;
    cout << "Deleted " << last->data << " from the end." << endl;
    
    delete last; // Delete the old last node
    last = temp; // Update last pointer
}

// CASE 3: Delete After a Particular Node
void deleteAfterNode(int targetVal) {
    if (last == NULL) return;

    Node* temp = last->next;

    do {
        if (temp->data == targetVal) {
            Node* nodeToDelete = temp->next;

            // If it's a single node list pointing to itself
            if (temp == nodeToDelete) {
                cout << "Only one node exists, nothing to delete after it." << endl;
                return;
            }

            // Bypass the nodeToDelete
            temp->next = nodeToDelete->next;

            // If the node we are deleting happens to be the last node, update last pointer
            if (nodeToDelete == last) {
                last = temp; 
            }

            cout << "Deleted " << nodeToDelete->data << " which was after " << targetVal << "." << endl;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    cout << "Target node " << targetVal << " not found!" << endl;
}

// ------------------------- DISPLAY & SEARCH -------------------------

void display() {
    if (last == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* temp = last->next; // Start at head
    cout << "CLL (using last): ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != last->next); // Stop when we circle back to head
    cout << "(Back to Head: " << last->next->data << ")" << endl;
}

void search(int key) {
    if (last == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* temp = last->next; // Start at head
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found " << key << " at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    
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