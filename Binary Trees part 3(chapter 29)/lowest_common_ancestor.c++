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
bool roottonode(Node* root,int n,vector<int> &path){
    if(root==NULL){
        return false;
    }
    
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }

    int isleft=roottonode(root->left,n,path);
    int isright=roottonode(root->right,n,path);

    if(isleft || isright){
        return true;
    }

    path.pop_back();
    return false;
}
int LCA(Node* root,int n1,int n2){
    vector<int> path1;
    vector<int> path2;

    roottonode(root,n1,path1);
    roottonode(root,n2,path2);

    int lca=-1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
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
   return leftLCA==NULL ? rightLCA : leftLCA;     //this statement say that if leftlca = null ? says return rightlca : means if left lca not null then return it.
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int n1=4;
    int n2=5;
    cout<<LCA(root,n1,n2);
    LCA2(root,n1,n2)->data;
    return 0;
    }