#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm> 
using namespace std;

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

void infixToPostfix(char s[], char postfix[]) {
    int postIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stacktop = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the character is an operand, add it to the output.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[postIndex] = c;
            postIndex++;
        }
        // If the character is '(', push it to the stack.
        else if (c == '(') {
            stack[++stacktop] = c;
        }
        // If the character is ')', pop and output from the stack until '(' is found.
        else if (c == ')') {
            while (stacktop >= 0 && stack[stacktop] != '(') {
                postfix[postIndex++] = stack[stacktop--];
            }
            stacktop--; // Pop '('
        }
        // If an operator is scanned
        else {
            while (stacktop >= 0 && (prec(s[i]) < prec(stack[stacktop]) || (prec(s[i]) == prec(stack[stacktop]) && s[i] != '^'))) {
                postfix[postIndex++] = stack[stacktop--];
            }
            stack[++stacktop] = c;
        }
    }

    while (stacktop >= 0) {
        postfix[postIndex++] = stack[stacktop--];
    }

    postfix[postIndex] = '\0'; 
}

void infixToPrefix(char s[]) {
    
    int len = strlen(s);
    reverse(s, s + len);

   
    for (int i = 0; i < len; i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    
    char postfix[1000];
    infixToPostfix(s, postfix);

    
    reverse(postfix, postfix + strlen(postfix));

    cout << "Prefix expression: " << postfix << endl;
}

int main() {
    char exp[] = "(A-B/C)*(A/K-L)";
  
    infixToPrefix(exp);

    return 0;
}
