#include <iostream>

class Node {
public:
    int data;       // Data field to store the value
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node with given data
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;     // Pointer to the head (first node) of the list

    LinkedList() : head(nullptr) {}    // Initialize an empty list

    // Function to append a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (head == nullptr) {
            head = newNode;  // If the list is empty, set head to the new node
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the last node
        }

        temp->next = newNode;  // Set the next of the last node to the new node
    }

    // Function to find the intersection of two sorted linked lists
    LinkedList* findIntersection(LinkedList* list2) {
        LinkedList* result = new LinkedList();  // Create a new list to store the intersection
        Node* p1 = head;
        Node* p2 = list2->head;

        // Traverse both lists to find common elements
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->data == p2->data) {
                result->append(p1->data);  // If both values are the same, add to the result
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->data < p2->data) {
                p1 = p1->next;  // Move the pointer in list1 forward
            }
            else {
                p2 = p2->next;  // Move the pointer in list2 forward
            }
        }

        return result;  // Return the result list containing the intersection
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    // Append some nodes to the first sorted list
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);
    list1.append(6);

    // Append some nodes to the second sorted list
    list2.append(2);
    list2.append(4);
    list2.append(6);
    list2.append(8);

    std::cout << "List 1:\n";
    list1.printList();

    std::cout << "List 2:\n";
    list2.printList();

    // Find the intersection of the two sorted linked lists
    LinkedList* intersection = list1.findIntersection(&list2);

    std::cout << "Intersection of List 1 and List 2:\n";
    intersection->printList();

    return 0;
}

 /*
 Intersection point of two nodes

 #include <iostream>

class Node {
public:
    int data;       // Data field to store the value
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node with given data
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;     // Pointer to the head (first node) of the list

    LinkedList() : head(nullptr) {}    // Initialize an empty list

    // Function to append a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);  // Create a new node
        if (head == nullptr) {
            head = newNode;  // If the list is empty, set head to the new node
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the last node
        }

        temp->next = newNode;  // Set the next of the last node to the new node
    }

    // Function to get the length of the linked list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Function to find the intersection point of two linked lists
    Node* getIntersectionNode(LinkedList* list2) {
        int len1 = this->getLength();
        int len2 = list2->getLength();

        Node* ptr1 = this->head;
        Node* ptr2 = list2->head;

        // Move the pointer of the longer list ahead by the difference in lengths
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                ptr1 = ptr1->next;
            }
        } else if (len2 > len1) {
            for (int i = 0; i < len2 - len1; i++) {
                ptr2 = ptr2->next;
            }
        }

        // Traverse both lists together to find the intersection point
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1 == ptr2) {
                return ptr1;  // Intersection point found
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return nullptr;  // No intersection
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    // Append some nodes to the first list
    list1.append(3);
    list1.append(6);
    list1.append(9);

    // Create a common node
    Node* common = new Node(15);
    list1.head->next->next->next = common;

    // Append some nodes to the second list
    list2.append(10);
    list2.head->next = common;

    // Continue with the common list after the intersection point
    common->next = new Node(30);

    std::cout << "List 1:\n";
    list1.printList();

    std::cout << "List 2:\n";
    list2.printList();

    // Find the intersection point of the two linked lists
    Node* intersection = list1.getIntersectionNode(&list2);

    if (intersection != nullptr) {
        std::cout << "Intersection Point: " << intersection->data << "\n";
    } else {
        std::cout << "No Intersection Point Found\n";
    }

    return 0;
}

 
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(char s[]) {
    char postfix[1000]; // to store string
    int postIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stacktop = -1;

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix[postIndex] = c;
            postIndex++;
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(')
        {
            ++stacktop;
            stack[stacktop] = c;
        }
        // If the scanned character is an ‘)’, pop and add to the output string from the stack until an ‘(‘ is encountered.
        else if (c == ')') {
            while (stacktop >= 0 && stack[stacktop] != '(')
            {
                postfix[postIndex] = stack[stacktop];
                postIndex++;
                stacktop--;
            }
            stacktop--; // Pop '('
        }
        // If an operator is scanned
        else {
            while ((stacktop >= 0 && (prec(s[i]) < prec(stack[stacktop])||prec(s[i]) == prec(stack[stacktop]))))
            {
                postfix[postIndex] = stack[stacktop];
                postIndex++;
                stacktop--;  
            }
            stacktop++;
            stack[stacktop] = c;
        }
    }

    // Pop all the remaining elements from the stack
    while (stacktop >= 0)
    {
                postfix[postIndex] = stack[stacktop];
                postIndex++;
                stacktop--;  
    }

    postfix[postIndex] = '\0';
    cout<<postfix;
}
void infixToPrefix(char s[]){
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;
 
    for (int i = 0; i < l; i++) {
 
        // If the scanned character is an
        // operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');
 
        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
 
            // Remove '(' from the stack
            char_stack.pop();
        }
 
        // Operator found
        else {
            if (isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    while (
                        getPriority(infix[i])
                        <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else {
                    while (
                        getPriority(infix[i])
                        < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
 
                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}
 
// Function to convert infix to prefix notation
string infixToPrefix(string infix)
{
    // Reverse String and replace ( with ) and vice versa
    // Get Postfix
    // Reverse Postfix
    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infixToPostfix(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}
// Driver code
int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
   // abcd^e-fgh*+^*+i-
  
  // Function call
    infixToPostfix(exp);

    return 0;
}


*/