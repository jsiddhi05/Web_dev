#include<iostream>
using namespace std;

class Node{
public:
    int coeff; // Coefficient of the term
    int pow;   // Power of the term
    Node *next;

    Node(int c, int p){  // Constructor to initialize coefficient and power
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class LL{
public:
    Node* head; // Head of the polynomial linked list
    
    LL(){  // Constructor initializing head to NULL
        head = NULL;
    }

    // Function to create a new node and add it to the polynomial linked list
    void create_node(int coeff, int pow){
        Node* nn = new Node(coeff, pow);
        if(head == NULL){
            head = nn;
        } else {
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    // Function to print the polynomial
    void printpoly(){
        if(head == NULL){
            cout << "Polynomial is empty!" << endl;
            return;
        }

        Node* temp = head;
        while(temp != NULL){
            cout << temp->coeff << "x^" << temp->pow;
            if(temp->next != NULL) cout << " + "; // Print + between terms
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to add two polynomials
    LL polyadd(LL l1, LL l2){
        Node *p1 = l1.head;
        Node *p2 = l2.head;
        LL result;

        while(p1 != NULL && p2 != NULL){
            if(p1->pow > p2->pow){
                result.create_node(p1->coeff, p1->pow);
                p1 = p1->next;
            } else if(p1->pow < p2->pow){
                result.create_node(p2->coeff, p2->pow);
                p2 = p2->next;
            } else {
                result.create_node(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        // Add remaining terms of the first polynomial
        while(p1 != NULL){
            result.create_node(p1->coeff, p1->pow);
            p1 = p1->next;
        }

        // Add remaining terms of the second polynomial
        while(p2 != NULL){
            result.create_node(p2->coeff, p2->pow);
            p2 = p2->next;
        }

        return result;
    }
};

int main(){
    LL poly1, poly2, result;

    // Creating the first polynomial: 3x^3 + 5x^2 + 6
    poly1.create_node(3, 3);
    poly1.create_node(5, 2);
    poly1.create_node(6, 0);

    // Creating the second polynomial: 4x^2 + 2x + 7
    poly2.create_node(4, 2);
    poly2.create_node(2, 1);
    poly2.create_node(7, 0);

    cout << "Polynomial 1: ";
    poly1.printpoly();
    
    cout << "Polynomial 2: ";
    poly2.printpoly();

    // Adding the two polynomials
    result = result.polyadd(poly1, poly2);

    cout << "Resultant Polynomial after Addition: ";
    result.printpoly();

    return 0;
}
