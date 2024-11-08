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
//using array spc nd time comp -> O(n)
bool checkpalindrome(node* &head){
    node* current=head;
    vector<int> arr;
    while(current!=NULL){
        arr.push_back(current->data);
        current=current->next;
    }
    int start=0,end=arr.size()-1;
    while(start<=end){
        if(arr[start]==arr[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}
// another logic in spc comp O(1) nd tym comp O(n)
// find the middle and then rev LL from middle to end nd then compare elem.
node* getmid(node* head){
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;              // slow will move 1 step nd fast will move 2 steps at the end 
    }                                       // slow will be at mid nd fast at last.
    return slow;
}
node* reverse(node* head){
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(node* &head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    node* current=head;
    // step 1 -> find middle
    node* mid=getmid(head);
    // step 2-> reverse LL after middle
    node* temp=mid->next;
    mid->next=reverse(temp);
    // step 3-> compare both halves
    node* head1=head;
    node* head2=mid->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    // step 4 -> make the LL as original (not compulsory)
    temp=mid->next;
    mid->next=reverse(temp);
    return true;
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
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    cout<<"linked list:"<<endl;
    print(head);
    cout<<"linked list is palindrome:"<<checkpalindrome(head)<<endl;
    cout<<"linked list is palindrome:"<<isPalindrome(head)<<endl;
    return 0;
}
