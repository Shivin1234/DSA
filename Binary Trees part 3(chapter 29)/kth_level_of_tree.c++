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
    currnode->right=buildTree(nodes);  //call for right subtree 
    return currnode;
}
void kthhelper(Node* root,int k,int currlevel){
    if(root==NULL){
        return;
    }
    if(currlevel==k){
        cout<<root->data<<" ";
        return;
    }
    kthhelper(root->left,k,currlevel+1);   //left subtree
    kthhelper(root->right,k,currlevel+1);  //right subtree
}
void kthlevel(Node* root,int k){
    kthhelper(root,k,1);
    cout<<endl;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes); 
    kthlevel(root,3);
    return 0;
    }