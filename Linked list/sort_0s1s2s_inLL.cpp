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
node* sort(node* &head){
    int zerocnt=0;
    int onecnt=0;
    int twocnt=0;
    node* current=head;
    while(current!=NULL){
        if(current->data==0){
            zerocnt++;
        }
        else if(current->data==1){
            onecnt++;
        }
        else{
            twocnt++;
        }
        current=current->next;
    }
    current=head;
    while(current!=NULL){
        if(zerocnt!=0){
            current->data=0;
            zerocnt--;
        }
        else if(onecnt!=0){
            current->data=1;
            onecnt--;
        }
        else{
            current->data=2;
            twocnt--;
        }
        current=current->next;
    }
}
// if we have to sort without data replacement
node* sort1(node* &head){
    node* current=head;
    while(current->next!=NULL){
        if(current->data >= current->next->data){
            swap(current->data,current->next->data);
        }
        current=current->next;
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
    insertAtHead(head,0);
    insertAtHead(head,1);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,2);
    cout<<"linked list before sorting:"<<endl;
    print(head);
    //sort(head);
    sort1(head);
    cout<<"linked list after sorting:"<<endl;
    print(head);
    return 0;
}