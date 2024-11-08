#include<iostream>
using namespace std;
class node{
    public:
      int data;
      node* left;
      node* right;
      node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
      }
};
int minElem(node* root){
    //base case
    int minelem=root->data;
    if(root==NULL || root->left==NULL){
        return minelem;
    }
    if(root->left->data < minelem){
        minelem=root->left->data;
        return minElem(root->left);
    }
}
int maxElem(node* root){
    //base case
    int maxelem=root->data;
    if(root==NULL || root->right==NULL){
        return maxelem;
    }
    if(root->right->data > maxelem){
        maxelem=root->right->data;
        return maxElem(root->right);
    }
}
node* minvalue(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* maxvalue(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
node* insertIntoBST(node* root,int d){
    //base case
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        //right part me insert krna hai
        root->right=insertIntoBST(root->right,d);
    }
    else{
        //left part me insert krna hai
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeinput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){
    node* root=NULL;
    cout<<"enter data to create BST"<<endl;
    takeinput(root);
    cout<<"Minimum element is BST is: "<<minvalue(root)->data<<endl;
    cout<<"Maximum element is BST is: "<<maxvalue(root)->data<<endl;
    cout<<"Minimum element is BST is: "<<minElem(root)<<endl;
    cout<<"Maximum element is BST is: "<<maxElem(root)<<endl;
}