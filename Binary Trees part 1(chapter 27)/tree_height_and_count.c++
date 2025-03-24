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
static int idx=-1;        //we used static int to increment value of idx wheather going upwards or downwords.

Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL; 
    }
    Node* currnode=new Node(nodes[idx]);
    currnode->left=buildTree(nodes);   //call for leftsubtree
    currnode->right=buildTree(nodes);  //call for right subtree 
    return currnode;
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);

    int currht=max(leftht,rightht)+1;
    return currht;
}
int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    int currcount=leftcount+rightcount+1;
    return currcount;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);

    cout<<"height is = "<<height(root)<<endl;
    cout<<"count is = "<<count(root)<<endl;

    Node* root2=new Node(5);
    root2->left=new Node(3);
    root2->right=new Node(4);
    cout<<"height 2 is = "<<height(root2)<<endl;
    cout<<"count 2 is = "<<count(root2)<<endl;
}