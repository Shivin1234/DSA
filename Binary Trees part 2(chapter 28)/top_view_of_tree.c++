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
void topview(Node *root){
    queue<pair<Node*,int>> q;    //(node,horizontal distace)
    map<int,int> m;     //(horizontal distace,node->data)

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> curr=q.front();
        q.pop();

        Node* currNode=curr.first;
        int currHD=curr.second;

        if(m.count(currHD) == 0){       //currhd==0 means HD does not exist currently in map.
            m[currHD]=currNode->data;
            }
        if(currNode->left!=NULL){
            pair<Node*,int> left=make_pair(currNode->left,currHD-1);
            q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int> right=make_pair(currNode->right,currHD+1);
            q.push(right);
        }
    }

    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    topview(root);
    return 0;
}