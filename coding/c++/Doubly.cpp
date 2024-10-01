#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }    

    // Parameterized constructor
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtStart(int data) {
        Node *nn = new Node(data);
        if (head == NULL) {
            head = nn;
        } else {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    void display() {
        Node *temp = head;
        while (temp != NULL) {
            if(temp->next!=NULL)
            cout << temp->data << "-> ";
            else
            cout<<temp->data<< endl;;
            temp = temp->next;
        }
       
    }
    void insertAtend(int data){
        Node *nn=new Node(data);
        
        if(head==NULL){
            head=nn;
            
        }else{
            Node *temp=head;
            while(temp->next!=NULL){
            temp=temp->next;
            }
            temp->next = nn;
            nn->prev = temp;
          
        }
    }
    void insertAtmiddle(int data,int val){
        Node *nn=new Node(data);
        if(head==NULL){
            head=nn;
            
        }else{
            Node *temp=head;
            
            while(temp->next->data!=val){
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
            nn->prev=temp;
            nn->next->prev=nn;
        }
    }
    void delectAtstart(){
        if(head==NULL){
            return;
        }else{
            head->next->prev=NULL;

            head = head->next;
           // cout<<head->prev->data;
            }
    }
    void delectAtend(){
        if(head==NULL){
            return;
        }else{
            Node *temp=head;
            while(temp->next!=NULL)
            {
                //cout<<temp->data<<endl;
                temp=temp->next;
                //temp->next=NULL;
            }
            //cout<<temp->data;
           // if(temp->next==NULL)
            temp->prev->next=NULL;
        }

    }
    void delectAtmiddle(int data,int val){
        if(head==NULL){
            return;
        }
        else{
            Node *temp=head;
            while(temp->data!=val){
                temp->prev->next=temp->next;
                
            }
        }
    }
        
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtend(5);
    dll.insertAtend(2);
    dll.insertAtend(4);
    dll.insertAtmiddle(9,2);
    dll.delectAtstart();
    dll.delectAtend();
    dll.display();

    return 0;
}
