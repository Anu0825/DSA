// C++ program to add two polynomials
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int coeff;
        int pow;
        Node* next;
        Node(int c, int p) {
            coeff = c;
            pow = p;
            next = nullptr;
        }
};

Node* addPolynomial(Node* head1, Node* head2) {
    Node* dummy = new Node(0, 0);
    
    // Node to append other nodes to the end 
    // of list
    Node* prev = dummy;
    
    Node* curr1 = head1, *curr2 = head2;
    
    while (curr1 != nullptr && curr2 != nullptr) {
        
        // if curr2.pow > curr1.pow, then 
        // append curr2 to list
        if (curr1->pow < curr2->pow) {
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
        
        // if curr1.pow > curr2.pow, then 
        // append curr2 to list
        else if (curr1->pow > curr2->pow) {
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        
        // else, add the sum of curr1->coeff and 
        // curr2->coeff to curr1->coeff, and append
        // curr1 to the list
        else {
            curr1->coeff = curr1->coeff + curr2->coeff;
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    
    // if curr1 if not null, then append the rest
    // to the list
    if (curr1 != nullptr) {
        prev->next = curr1;
    }
    
    // if curr2 if not null, then append the rest
    // to the list
    if (curr2 != NULL) {
        prev->next = curr2;
    }
    
    return dummy->next;
}

void printList(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->coeff << "," << curr->pow << " ";
        curr = curr->next;
        
    }
    
    cout<<endl;
}

int main() {
    
    // 1st polynomial: 5x^2+4x^1+2x^0
    Node* head1 = new Node(5,2); 
    head1->next = new Node(4,1);
    head1->next->next = new Node(2,0);
    
    // 2nd polynomial: -5x^1-5x^0
    Node* head2 = new Node(-5,1); 
    head2->next = new Node(-5,0);

    Node* head = addPolynomial(head1, head2);
    
    printList(head);
}
