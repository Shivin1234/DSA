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
Node* LCA2(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftLCA=LCA2(root->left,n1,n2);
    Node* rightLCA=LCA2(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
   /* else if(leftLCA==NULL && rightLCA!=NULL){
        return rightLCA;
    }
    else if(leftLCA!=NULL && rightLCA==NULL){
        return leftLCA;
    }
    else(leftLCA==NULL && rightLCA==NULL){
        return NULL;
    }*/
   return leftLCA==NULL ? rightLCA : leftLCA;
}
int dist(Node* root,int n){
    if(root==NULL){
        return -1;
    }
    
    if(root->data==n){
        return 0;
    }
    int leftdist=dist(root->left,n);
    int righttdist=dist(root->right,n);
    if(leftdist!=-1){
        return leftdist+1;
    }else if(righttdist!=-1){
        return righttdist+1;
    }
    return -1;
    
}
int mindist(Node* root,int n1,int n2){
    Node* lca=LCA2(root,n1,n2);

    int dist1=dist(lca,n1);
    int dist2=dist(lca,n2);

    return dist1+dist2;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int n1=4,n2=6;  
    cout<<mindist(root,n1,n2);
    return 0;
    }