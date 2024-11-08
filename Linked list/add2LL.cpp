// add two LL eg. -> 1. 2->3->4 nd 2. 6->2 ans= 234+62=296 2->9->6
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
node* add(node* &head1,node* &head2){
    // step1 -> reverse both LL
    head1=reverse(head1);
    head2=reverse(head2);
    // step 2 -> add both LL
    node* ans=NULL;
    node* curr1=head1;
    node* curr2=head2;
    int carry=0;
    while(curr1!=NULL && curr2!=NULL){
        int sum=curr1->data+curr2->data+carry;
        int res=sum%10;
        insertAtHead(ans,res);
        carry=sum/10;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    while(curr1!=NULL){
        int sum=carry+curr1->data;
        int res=sum%10;
        insertAtHead(ans,res);
        carry=sum/10;
        curr1=curr1->next;
    }
    while(curr2!=NULL){
        int sum=carry+curr2->data;
        int res=sum%10;
        insertAtHead(ans,res);
        carry=sum/10;
        curr2=curr2->next;
    }
    while(carry!=0){
        int sum=carry;
        int res=sum%10;
        insertAtHead(ans,res);
        carry=sum/10;
    }
    return ans;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtHead(head1,4);
    insertAtHead(head1,3);
    insertAtHead(head1,2);
    insertAtHead(head2,2);
    insertAtHead(head2,6);
    cout<<"linked list 1:"<<endl;
    print(head1);
    cout<<"linked list 2:"<<endl;
    print(head2);
    node* ans=add(head1,head2);
    print(ans);
    return 0;
}
/*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
*/