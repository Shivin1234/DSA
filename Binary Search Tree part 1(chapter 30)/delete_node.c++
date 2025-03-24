#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val < root->data){
        root->left=insert(root->left,val);
    }
    else if(val > root->data){
        root->right=insert(root->right,val);
    }
    return root;
}

Node* buildBST(int arr[],int n){
    Node* root=NULL;

    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data > key){
        return search(root->left,key);
    }else if(root->data < key){
        return search(root->right,key);
    }
}
Node* getinordersuccessor(Node* root){
    while(root->left != NULL){
        root=root->left;
    }
    return root;
}
Node* delnode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val < root->data){                      //case 1: when val < root
        root->left = delnode(root->left,val);
    }else if(val > root->data){                //case 2: when val > root
        root->right = delnode(root->right,val);
    }else{                                     //case 3: when val = root
        //case 1: 0 children case
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //case 2: 1 children case
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL ? root->right : root->left;
        }
        //case 3: 2 chlidren case
        Node* IS = getinordersuccessor(root->right);
        root->data = IS->data;
        root->right = delnode(root->right,IS->data);
    return root;
    }
}
int main(){
    int arr[6]={5,1,3,4,2,7};
    Node* root=buildBST(arr,6);

    inorder(root);
    cout<<endl;
    delnode(root,4);
    inorder(root);
    cout<<endl;
}