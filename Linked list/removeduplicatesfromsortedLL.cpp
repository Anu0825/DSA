#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    } 
};
node* RemoveDuplicates(node* head){
    //empty list
    if(head==NULL){
        return NULL;
    }
    //non empty list
    node* current=head;
    while(current->next!=NULL){
    if(current-> data==current->next->data){
        node* nxt_nxt=current->next->next;
        delete(current-> next);
        current->next=nxt_nxt;
    }
    else{
        current=current->next;
    }
    }
    return head;
}
void insertAtHead(node* &head,int d){
    //new node create
    node* temp=new node(d);
    temp -> next=head;
    head=temp;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp=temp -> next;
    }
    cout<<endl;
}
int main(){
    node* head=NULL;
    insertAtHead(head,20);
    insertAtHead(head,20);
    insertAtHead(head,13);
    insertAtHead(head,13);
    insertAtHead(head,13);
    insertAtHead(head,11);
    cout<<"linked list before dupliacte removal:"<<endl;
    print(head);
    RemoveDuplicates(head);
    cout<<"linked list after dupliacte removal:"<<endl;
    print(head);
    return 0;
}
