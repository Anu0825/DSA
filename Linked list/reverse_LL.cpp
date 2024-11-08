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
void insertAtHead(node* head,int data){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}
void print(node* head){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* reverseLL(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* forward=NULL;
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    }
    return prev;
}

int main(){

}