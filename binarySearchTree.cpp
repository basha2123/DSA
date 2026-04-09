#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val < root->data){
        root -> left = insert(root->left, val);
    }
    else{
        root -> right = insert(root -> right, val);
    }
    return root;
}

void search(Node* root, int val){
    if(root == nullptr){
        cout << "Not Found";
        return;
    }
    if(root->data == val){
        cout << "Found";
        return;
    }
    else if(val < root->data){
        search(root -> left, val);
    }
    else{
        search(root -> right, val);
    }
}

void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    inorder(root -> left);
    cout << root->data << " ";
    inorder(root -> right);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int main(){
    Node* root = nullptr;
    
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 9);
    
    inorder(root);
    
    search(root, 4);
    
    return 0;
}
