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
class Info{
    public:
        bool isBST;
        int min;
        int max;
        int sz;
        Info(bool isBST,int min,int max,int sz){
            this->isBST=isBST;
            this->min=min;
            this->max=max;
            this->sz=sz;
        }
};
static int maxsize;
Info* largestbst(Node* root){
    if(root==NULL){
        return new Info(true,INT16_MAX,INT16_MIN,0);
    }
    // if(root==NULL){                                      //2 base case example
    //      return NULL;
    // }
    // if(root->left==NULL && root->right==NULL){
    //     new Info(true,root->data,root->data,1);
    // }
    Info* leftinfo=largestbst(root->left);
    Info* rightinfo=largestbst(root->right);

    int currmin = min(root->data,min(leftinfo->min,rightinfo->min));
    int currmax = max(root->data,max(leftinfo->max,rightinfo->max));
    int currsz = leftinfo->sz + rightinfo->sz + 1; 
    
    if(leftinfo->isBST && rightinfo->isBST
        && root->data > leftinfo->max
        && root->data < rightinfo->min){
            maxsize=max(maxsize,currsz);
            return new Info(true,currmin,currmax,currsz);

        }else{
            return new Info(false,currmin,currmax,currsz);
        }
}
int main(){
    Node* root=new Node(50);
    root->left=new Node(30);
    root->left->left=new Node(5);
    root->left->right=new Node(2);

    root->right=new Node(60);
    root->right->left=new Node(45);
    root->right->right=new Node(70);
    root->right->right->left=new Node(65);
    root->right->right->right=new Node(80);

    largestbst(root);
    cout<<"maxsize is : "<<maxsize<<endl;
    return 0;
}