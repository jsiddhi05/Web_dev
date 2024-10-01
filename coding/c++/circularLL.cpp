#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string text;
    Node* next;
    Node* prev;

    // Default constructor
    Node() : text(""), next(nullptr), prev(nullptr) {}

    // Parameterized constructor
    Node(string t) : text(t), next(nullptr), prev(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Add route at the start
    void addFromStart(string text) {
        Node* newNode = new Node(text);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Route \"" << text << "\" added at start!" << endl;
    }

    // Add route at the end
    void addFromEnd(string text) {
        Node* newNode = new Node(text);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Route \"" << text << "\" added at end!" << endl;
    }

    // Add route after a specific route
    void addFromMiddle(string newText, string existingText) {
        if (head == nullptr) {
            cout << "No routes to insert after!" << endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->text == existingText) {
                Node* newNode = new Node(newText);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                cout << "Route \"" << newText << "\" added after \"" << existingText << "\"!" << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Route \"" << existingText << "\" not found!" << endl;
    }

    // Remove route from the start
    void removeFromStart() {
        if (head == nullptr) {
            cout << "No routes to remove!" << endl;
            return;
        }

        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* oldHead = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete oldHead;
        }
        cout << "Route removed from start!" << endl;
    }

    // Remove route from the end
    void removeFromEnd() {
        if (head == nullptr) {
            cout << "No routes to remove!" << endl;
            return;
        }

        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
            delete tail;
        }
        cout << "Route removed from end!" << endl;
    }

    // Remove route from the middle
    void removeFromMiddle(string text) {
        if (head == nullptr) {
            cout << "No routes to remove!" << endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->text == text) {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                cout << "Route \"" << text << "\" removed from middle!" << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Route \"" << text << "\" not found!" << endl;
    }

    // Display all routes
    void displayRoutes() {
        if (head == nullptr) {
            cout << "No routes to display!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->text;
            if (temp->next != head) {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice;
    string text, existingText;

    do {
        cout << "\nNavigation System Menu:\n";
        cout << "1. Add route at start\n";
        cout << "2. Add route at end\n";
        cout << "3. Add route after a specific route\n";
        cout << "4. Remove route from start\n";
        cout << "5. Remove route from end\n";
        cout << "6. Remove route from middle\n";
        cout << "7. Display routes\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter route to add at start: ";
                cin >> text;
                cll.addFromStart(text);
                break;
            case 2:
                cout << "Enter route to add at end: ";
                cin >> text;
                cll.addFromEnd(text);
                break;
            case 3:
                cout << "Enter new route to add: ";
                cin >> text;
                cout << "Enter existing route after which to add: ";
                cin >> existingText;
                cll.addFromMiddle(text, existingText);
                break;
            case 4:
                cll.removeFromStart();
                break;
            case 5:
                cll.removeFromEnd();
                break;
            case 6:
                cout << "Enter route to remove from middle: ";
                cin >> text;
                cll.removeFromMiddle(text);
                break;
            case 7:
                cll.displayRoutes();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
