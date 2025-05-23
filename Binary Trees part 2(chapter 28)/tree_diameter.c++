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
int diameter(Node* root){        //diameter of tree is maximum distance between the 2 leaf nodes of the tree.
    if(root==NULL){
        return 0;
    }
    int currdia=height(root->left)+height(root->right)+1;
    int leftdia=diameter(root->left);
    int rightdia=diameter(root->right);
    int maxdia=max(currdia,max(leftdia,rightdia));
    return maxdia;
}
pair<int,int> diameter2(Node* root){       //more optimized code with better time complexity.
    if(root==NULL){
        return make_pair(0,0);
    }
    //(diameter,height)
    pair<int,int> leftinfo=diameter2(root->left);
    pair<int,int> rightinfo=diameter2(root->right);

    int currdia=leftinfo.second+rightinfo.second+1;
    int finaldia=max(currdia,max(leftinfo.first,rightinfo.first));
    int finalht=max(leftinfo.second,rightinfo.second)+1;

    return make_pair(finaldia,finalht);
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout<<"diameter is = "<<diameter(root)<<endl;
    cout<<"diameter is = "<<diameter2(root).first<<endl;
    return 0;
}