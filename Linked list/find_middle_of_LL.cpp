#include<iostream>
#include<vector>
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
node* getMiddle(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
int getLength(node* head){
    if(head==NULL){
        return 0;
    }
    node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
node* findMiddle(node* &head){
    int len=getLength(head);
    int ans=len/2;
    node* temp=head;
    while(ans--){
        temp=temp->next;
    }
    return temp;
}
int main(){
    node* head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    cout<<"linked list:"<<endl;
    print(head);
    cout<<"middle: "<<getMiddle(head) -> data<<endl;
    cout<<"middle: "<<findMiddle(head) -> data<<endl;
    return 0;
}