#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
        unordered_map<char,Node*> children;
        bool endofword;
        int freq;

        Node(){
            endofword=false;
        }
};

class Trie{
        Node* root;
    public:
        Trie(){
            root=new Node();
            root->freq=-1;
        }
        void insert(string key){
            Node* temp=root;
            for(int i=0;i<key.size();i++){
                if(temp->children[key[i]]==0){
                    temp->children[key[i]]=new Node();
                    temp->children[key[i]]->freq=1;
                }else{
                    temp->children[key[i]]->freq++;
                }
                temp=temp->children[key[i]];
            }
            temp->endofword=true;
        }
        bool search(string key){
            Node* temp=root;
            for(int i=0;i<key.size();i++){
                if(temp->children.count(key[i])){
                    temp=temp->children[key[i]];
                }else{
                    return false;
                }
            }
            return temp->endofword;
        }
        int counthelper(Node* root){
            int ans=0;

            for(pair<char,Node*> child : root->children){
                ans+=counthelper(child.second);
            }
            return ans+1;
        }
        int countNodes(){
                return counthelper(root); 
        }
    };
int countuniquesubstr(string str){
    Trie trie;
    //find suffix
    for(int i=0;i<str.size();i++){
        string suffix=str.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();
}
int main(){
    string str="ababa";
    cout<<countuniquesubstr(str)<<endl;
    return 0;
}