#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr; //if anyone of it is null return
        ListNode *temp1=headA;
        ListNode *temp2=headB;

        while(temp1!=temp2){
            if(temp1==nullptr)
            temp1=headB;
        else temp1=temp1->next;
            if(temp2==nullptr)
            temp2=headA;
        else temp2=temp2->next;
        }
        return temp1;
        
    }
     void print(ListNode* head){
        while(head){
            cout << head->val << " -> ";
            head=head->next;
        }
        cout<<"nullprt"<<endl;
     }
};
int main(){

    ListNode* intersect=new ListNode(2);
    intersect->next=new ListNode(4);

    ListNode * headA=new ListNode(1);
    headA->next=new ListNode(9);
    headA->next->next=new ListNode(7);
    headA->next->next->next= intersect;

    ListNode *headB=new ListNode(3);
    headB->next=intersect;

    Solution solution;
    ListNode *result=solution.getIntersectionNode(headA,headB);

    if(result){
        cout<<"Intersection at node with value:"<<result->val<<endl;
    }else{
        cout<<"No intersection"<<endl;
    }
    return 0;

}