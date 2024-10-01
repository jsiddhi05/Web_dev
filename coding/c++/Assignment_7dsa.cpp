#include<iostream>
#include<string>
using namespace std;

class Node{
 public:    
    string data;
    Node* next;

    Node(string val){
        data=val;
        next=NULL;
    }
};
class Stack{
 private:
    Node* top;
 public:
    Stack(){
        top=nullptr;
    }
    
    void push(string val){
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
    }
    string pop(){
        if(isEmpty()){
            cout<<"No pages in history";
            return "";

        }
        Node* temp=top;
        string val= top->data;
        top=top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
class BrowserHistory{
private:
    Stack history;
    string currPage;
public:
   BrowserHistory(){
    currPage="Home";
   }        
   void VisitPage(string page){
    if(!currPage.empty()){
        history.push(currPage);
    }
    currPage=page;
    cout<<"Visited"<<currPage<<"\n";
   }
   void goBack(){
    if(history.isEmpty()){
        cout<<"No pages in the history to go back \n";
    }
    currPage=history.pop();
    cout<<"navigated back to:"<<currPage<<"\n";
   }
    void viewCurrentPage() {
        cout << "Current Page: " << currPage << "\n";
    }

    bool isHistoryEmpty() {
        return history.isEmpty();
    }
};
int main(){
    BrowserHistory browser;
    int choice;
    string url;

    do {
        cout << "\nBrowser History Menu\n";
        cout << "1. Visit a page\n";
        cout << "2. Go back to previous page\n";
        cout << "3. View current page\n";
        cout << "4. Check if history is empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter the URL of the page to visit: ";
                cin >> url;
                browser.VisitPage(url);
                break;

            case 2: 
                browser.goBack();
                break;

            case 3: 
                browser.viewCurrentPage();
                break;

            case 4: 
                if (browser.isHistoryEmpty()) {
                    cout << "History is empty.\n";
                } else {
                    cout << "History is not empty.\n";
                }
                break;

            case 5: 
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;

}


