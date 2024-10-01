 #include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string text;
    Node* next;
    Node* prev;

    // Default constructor
    Node() {
        next = nullptr;
        prev = nullptr;
    }

    // Parameterized constructor
    Node(string t) {
        text = t;
        next = nullptr;
        prev = nullptr;
    }
};

class TextEditor {
private:
    Node* head;

public:
    TextEditor() {
        head = nullptr;
    }

    // Insert text at the start
    void insertAtStart(string text) {
        Node* newNode = new Node(text);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert text at the end
    void insertAtEnd(string text) {
        Node* newNode = new Node(text);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert text after the current node
    void insertAfterCurrent(string text, Node* curr) {
        if (curr == nullptr) {
            cout << "Current node is null!" << endl;
            return;
        }

        Node* newNode = new Node(text);
        newNode->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    // Delect text at the start (without using 'delete')
    void delectAtStart() {
        if (head == nullptr) {
            cout << "No text to remove!" << endl;
            return;
        }

        Node* temp = head;  // Store the current head

        // If there's only one node
        if (head->next == nullptr) {
            head = nullptr;  // Set head to null
        } else {
            head = head->next;  // Move head to the next node
            head->prev = nullptr;  // Remove the backward link to the old head
        }

        cout << "Text \"" << temp->text << "\" removed from start!" << endl;
        delete temp;  // Free the memory
    }

    // Delect text at the end (without using 'delete')
    void delectAtEnd() {
        if (head == nullptr) {
            cout << "No text to remove!" << endl;
            return;
        }

        Node* temp = head;

        // If there's only one node
        if (temp->next == nullptr) {
            head = nullptr;
            delete temp;  // Free the memory
        } else {
            // Traverse to the last node
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Remove the link to the last node
            temp->prev->next = nullptr;
            delete temp;  // Free the memory
        }

        cout << "Text removed from end!" << endl;
    }

    // Display all text from start to end
    void displayText() {
        if (head == nullptr) {
            cout << "Text buffer is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->next != nullptr)
                cout << temp->text << " -> ";
            else
                cout << temp->text << endl;
            temp = temp->next;
        }
    }

    // Display all text in reverse order
    void displayReverseText() {
        if (head == nullptr) {
            cout << "Text buffer is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            if (temp->prev != nullptr)
                cout << temp->text << " <- ";
            else
                cout << temp->text << endl;
            temp = temp->prev;
        }
    }

    // Search for a specific text
    void searchText(string searchText) {
        if (head == nullptr) {
            cout << "Text buffer is empty!" << endl;
            return;
        }

        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->text == searchText) {
                cout << "Text found: " << searchText << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Text not found!" << endl;
        }
    }

    // Function to get the head node (for demonstration purposes)
    Node* getHead() {
        return head;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string text;
    Node* curr = nullptr;

    do {
        cout << "\nText Editor Menu:\n";
        cout << "1. Insert text at start\n";
        cout << "2. Insert text at end\n";
        cout << "3. Set current node (for insertion)\n";
        cout << "4. Insert text after the current node\n";
        cout << "5. Delect text at start\n";
        cout << "6. Delect text at end\n";
        cout << "7. Display text\n";
        cout << "8. Display text in reverse\n";
        cout << "9. Search text\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To handle the newline character after input

        switch (choice) {
            case 1:
                cout << "Enter text to insert at start: ";
                cin >> text;
                editor.insertAtStart(text);
                break;
            case 2:
                cout << "Enter text to insert at end: ";
                cin >> text;
                editor.insertAtEnd(text);
                break;
            case 3:
                // Set current node for demonstration (for simplicity, set to head here)
                curr = editor.getHead();
                if (curr != nullptr) {
                    cout << "Current node is set to: " << curr->text << endl;
                } else {
                    cout << "No nodes in the buffer to set as current!" << endl;
                }
                break;
            case 4:
                if (curr == nullptr) {
                    cout << "No current node set!" << endl;
                    break;
                }
                cout << "Enter text to insert after current node: ";
                cin >> text;
                editor.insertAfterCurrent(text, curr);
                break;
            case 5:
                editor.delectAtStart();
                break;
            case 6:
                editor.delectAtEnd();
                break;
            case 7:
                editor.displayText();
                break;
            case 8:
                editor.displayReverseText();
                break;
            case 9:
                cout << "Enter text to search: ";
                cin >> text;
                editor.searchText(text);
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
