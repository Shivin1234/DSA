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
    void printinrange(Node* root,int start,int end){
        if(root==NULL){
            return;
        }
        if(start <= root->data && root->data <= end){          //case 1
            cout<<root->data<<" ";
            printinrange(root->left,start,end);
            printinrange(root->right,start,end);
        }else if(root->data < start){
            printinrange(root->right,start,end);              //case 2
        } else{                                              //case 3 
            printinrange(root->left,start,end);
        } 
    }
int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);

    printinrange(root,5,12);
    cout<<endl;

}