#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    currnode->right=buildTree(nodes);  //call for rightsubtree 
    return currnode;
}
int KthAncestor(Node* root,int node,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 0;
    }
    int leftdist=KthAncestor(root->left,node,k);
    int rightdist=KthAncestor(root->right,node,k);

    if(leftdist==-1 && rightdist==-1){
        return -1;
    }

    int validval=leftdist == -1 ? rightdist : leftdist;
    if(validval+1==k){
        cout<<root->data<<endl;
    }
    return validval+1;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int node=5,k=2;
    KthAncestor(root,node,k);
    return 0;
}