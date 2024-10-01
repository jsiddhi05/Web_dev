class LinkList{
    public static class Node{
    int data;
    Node next;
    public Node(int data){
        this.data=data;
        this.next=null;
    }
 }
  public static Node head;
  public static Node tail;
  public static int size;
  
  public void addFirst(int data){
      //step 1=create new node
      Node newNode=new Node(data);
      if(head==null){
          head=tail=newNode;
          return;
      }
      
      //step 2-newNode next=head
      newNode.next=head;//link
      
      //step 3-head =newHead next=hard
      head =newNode;
  }
  public void addLast(int data){
      Node newNode=new Node(data);
      if(head==null){
          head=tail=newNode;
          return;
      }
      tail.next=newNode;
      tail=newNode;
  }
  public void print(){
      if(head==null){
          System.out.print("LL is empty");
          return;
      }
      Node temp=head;
      while(temp!=null){
          System.out.print(temp.data+"->");
          temp=temp.next;
      }
      System.out.println("NULL");
  }
  public void add(int idx,int data){
    Node newNode=new Node(data);
    Node temp=head;
    int i=0;
    while(i<idx-1){
        temp=temp.next;
        i++;
    }
    //i=idx-1 temp-->prev;
    newNode.next=temp.next;
    temp.next=newNode;
  }
  public void delectNthfromEnd(int n){
    int sz=0;
    Node temp=head;
    while(temp!=null){
       temp=temp.next;
       sz++;
    }
    if(n==sz){
        head=head.next;//remove first
        return;
    }
    int i=1;
    int iToFind=sz-n;
    Node prev=head;
    while(i<iToFind){
        prev=prev.next;
        i++;
    }
    prev.next=prev.next.next;

  }
  public static void main(String args[]){
      LinkList ll=new LinkList();
      ll.print();
      ll.addFirst(2);
      ll.print();
      ll.addFirst(1);
      ll.print();
      ll.addLast(3);
      ll.print();
      ll.addLast(4);
      ll.print();
      ll.add(2,9);
      ll.print();
      ll.delectNthfromEnd(3);
      ll.print();
  }
      
      
  }
