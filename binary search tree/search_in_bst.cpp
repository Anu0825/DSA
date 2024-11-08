// return true if elem is present in tree else false
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
bool searchInBST(node* root,int x){
    // base case
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data > x){
        // left part me
        return searchInBST(root->left,x);
    }
    else{
        //right part me
        return searchInBST(root->right,x);
    }
}
bool searchwithoutRecursion(node* root,int x){
    node *temp=root;
    while(temp!=NULL){
        if(temp->data ==x){
            return true;
        }
        if(temp->data > x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;

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
    int x;
    cout<<"enter element:";
    cin>>x;
    cout<<"element present or not ->"<<searchInBST(root,x)<<endl;
    cout<<"element present or not ->"<<searchwithoutRecursion(root,x)<<endl;
}