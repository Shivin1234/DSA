#include<iostream>
#include<vector>
#include<queue>
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
void levelorder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
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
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    levelorder(root);
    levelorder2(root);
    return 0;
}