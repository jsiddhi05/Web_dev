#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LL {
public:
    Node* head;

    LL() {
        head = NULL;
    }

    void insertAtStart(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

     void insertAtMiddle(int data, int val) {
        Node* nn = new Node(data); // Create the new node

        // Special case: if the list is empty or inserting at the start
        if (head == nullptr || head->data == val) {
            nn->next = head;
            head = nn;
            return;
        }

        // Traverse the list to find the node with the value `val`
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        // If the value `val` was found, insert `nn` after the node with `val`
        if (temp->next != nullptr) {
            nn->next = temp->next;
            temp->next = nn;
        } else {
            // If `val` was not found, just append `nn` at the end
            temp->next = nn;
        }
    }
     void deleteAtStart() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        
        Node* temp = head; 
        head = head->next; 

        
    }
    void deleteAtMiddle(int val) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        
        // Special case: if the node to delete is the head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            // Simulate the deletion of the node without using 'delete'
            // Normally you would use 'delete temp' here
            return;
        }

        // Traverse the list to find the node to delete
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        // If the node with value `val` was found
        if (temp->next != nullptr) {
            Node* nodeToRemove = temp->next; // Node to be "deleted"
            temp->next = temp->next->next;
            // Simulate the deletion of the node without using 'delete'
            // Normally you would use 'delete nodeToRemove' here
        } else {
            cout << "Node with value " << val << " not found." << endl;
        }
    }
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        
        if (head->next == nullptr) {
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next; 
        }
        Node* toDelete = temp->next; 
        temp->next = nullptr; 
    }

        

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LL list; // Create an instance of the LL class
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtStart(6);
    list.insertAtMiddle(9, 2);
    list.deleteAtMiddle(9);
    //list.deleteAtStart(); // Insert 3 at index 2
    list.display(); // Display the list
    return 0;
}
