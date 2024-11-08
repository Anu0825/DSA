//other approach-> first sort linked list and then remove duplicates -> time comp O(nlogn)
#include<iostream>
#include<unordered_map>
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
//time comp. O(n^2)
node* RemoveDuplicates(node* head){
    //empty list
    if(head==NULL){
        return NULL;
    }
    //non empty list
    node* current=head;
    node* temp=head;
    while(current->next!=NULL){
    if(current-> data==temp->next->data){
        node* nxt_nxt=temp->next->next;
        delete(temp-> next);
        temp->next=nxt_nxt;
    }
    else{
        temp=temp->next;
    }
    if(temp->next==NULL){
        current=current->next;
        temp=current;
    }
    }
    return head;
}
//using maps time comp O(n) nd space comp O(n)
node* remDup_map(node* head){
    unordered_map<int,bool> visited;
    node* current=head;
    node* prev=NULL;
    while(current!=NULL){
        if(visited[current->data]){
        prev->next=current->next;
        delete(current);
    }
       else{
        visited[current->data]=true;
        prev=current;
        current=current->next;
       }
       current=prev->next;
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
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,2);
    cout<<"linked list before dupliacte removal:"<<endl;
    print(head);
    //RemoveDuplicates(head);
    remDup_map(head);
    cout<<"linked list after dupliacte removal:"<<endl;
    print(head);
    return 0;
}
