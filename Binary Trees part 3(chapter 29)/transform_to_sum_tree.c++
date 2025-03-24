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
void levelorder2(Node* root){         //child nodes on different lines.
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    }
}
int transform(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftold=transform(root->left);
    int rightold=transform(root->right);
    int currold=root->data;

    root->data=leftold+rightold;
    if(root->left!=NULL){
    root->data+=root->left->data;
    }
    if(root->right!=NULL){
    root->data+=root->right->data;
    }
    return currold;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    transform(root);
    levelorder2(root);

    return 0;
}