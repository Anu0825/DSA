#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data){
        this -> data=data;
        this -> next=NULL;
    }
    //destructor
    ~node(){
        int value=this -> data;
        //memory free
        if(this -> next !=NULL){
            delete next;
            this ->next =NULL;
        } 
        cout<<"memory is free for node with data "<<value<<endl;
        }
};
void insertAtHead(node* &head,int d){
    //new node create
    node* temp=new node(d);
    temp -> next=head;
    head=temp;
}
void insertAtTail(node* &tail,int d){
    //new node create
    node* temp=new node(d);
    tail -> next=temp;
    tail=tail -> next;
}
void insertAtPosition(node* &tail,node* &head,int position,int d){
    //insert at start
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt < position-1){
        temp =temp -> next;
        cnt++;
    }
    //inserting at last position
    if(temp -> next== NULL){    
        insertAtTail(tail,d);
        return ;
    }
    //creating a node for d
    node* nodeToInsert=new node(d);
    nodeToInsert -> next=temp -> next;
    temp -> next= nodeToInsert;
}
void print(node* &head){
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp=temp -> next;
    }
    cout<<endl;
}
void deleteNode(int position,node* &head){
    //deleting first or start node
    if(position ==1){
        node* temp=head;
        head =head -> next;
        temp -> next= NULL;
        // memory free start node
        delete temp;
    }
    else{
        // deleting any middle node or last node
        node* current=head;
        node* previous=NULL;

        int cnt=1;
        while(cnt < position){
            previous=current;
            current=current -> next;
            cnt++;
        }
        previous  -> next=current -> next;
        current -> next=NULL;
        delete current;
    }
}


int main(){
    // created a new node
    node* node1=new node(10);
    //cout<<node1 -> data <<endl;
    //cout<<node1 -> next <<endl;

    //head pointed to node
    node* head=node1;
    node* tail=node1;
    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,15);
    print(head);
    insertAtTail(tail,25);
    print(head);
    insertAtTail(tail,22);
    print(head);
    insertAtPosition(tail,head,3,55);
    print(head);
    insertAtPosition(tail,head,1,90);
    print(head);
    insertAtPosition(tail,head,6,70);
    print(head);
    deleteNode(1,head);
    print(head);
    return 0;   
}
