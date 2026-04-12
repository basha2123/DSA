// TREE TRAVERSALS(INORDER, PREORDER, POSTORDER)

#include <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* createNode(int value){
    node* newnode = new node();
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
   
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
    
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}


int main() {
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);

  
    return 0;
}
