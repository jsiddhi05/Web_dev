#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string text;
    Node* next;

    // Default constructor
    Node() : text(""), next(nullptr) {}

    // Parameterized constructor
    Node(string t) : text(t), next(nullptr) {}
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
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
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
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
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

        if (head->next == head) {  // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* oldHead = head;
            head = head->next;
            temp->next = head;
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

        if (head->next == head) {  // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "Route removed from end!" << endl;
    }

    // Remove route from the middle
    void removeFromMiddle(string text) {
        if (head == nullptr) {
            cout << "No routes to remove!" << endl;
            return;
        }

        if (head->text == text) {
            removeFromStart();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        do {
            prev = temp;
            temp = temp->next;
            if (temp->text == text) {
                prev->next = temp->next;
                delete temp;
                cout << "Route \"" << text << "\" removed from middle!" << endl;
                return;
            }
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
