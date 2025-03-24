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
Node* buildBST(vector<int> arr,int st,int end){
    if(st > end){
        return NULL;
    }
    int mid=(st+end)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=buildBST(arr,st,mid-1);
    curr->right=buildBST(arr,mid+1,end);
    return curr;
}
void inorder(Node* root,vector<int> &nodes){
    if(root==NULL){
        return;
    }
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}
Node* balancedBST(Node* root){

    vector<int> nodes;
    inorder(root,nodes);
    return buildBST(nodes,0,nodes.size()-1);
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root=new Node(6);
    root->left=new Node(5);
    root->left->left=new Node(4);
    root->left->left->left=new Node(3);

    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->right=new Node(9);

    root=balancedBST(root);
    preorder(root);
    cout<<endl;
    return 0;
}