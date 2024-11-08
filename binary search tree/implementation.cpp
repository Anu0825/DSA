#include<iostream>
#include<queue>
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
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

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
    cout<<"printing the BST:"<<endl;
    levelOrderTraversal(root);
    cout<<"printing inorder: ";
    inorder(root);
    cout<<endl<<"printing preorder: ";
    preorder(root);
    cout<<endl<<"printing postorder: ";
    postorder(root);
    return 0;
}