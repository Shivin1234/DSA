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

        string getprefix(string key){
            Node* temp=root;
            string prefix="";
            for(int i=0;i<key.size();i++){
                prefix+=key[i];
                if(temp->children[key[i]]->freq==1){
                    break;
                }
                temp=temp->children[key[i]];
            }
            return prefix;
        }
};
//------------------------------wordbreak problem-----------------------------------------------------------//
bool helper(Trie &trie,string key){
    if(key.size()==0){
        return true;
    }
    for(int i=0;i<key.size();i++){
        string first=key.substr(0,i+1);
        string second=key.substr(i+1);
    if(trie.search(first) && helper(trie,second)){
        return true;
        }
    } 
    return false;
}
bool wordbreak(vector<string> dict,string key){
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    return helper(trie,key);
}

void prefixproblem(vector<string> dict){
    Trie trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    for(int i=0;i<dict.size();i++){
        cout<<trie.getprefix(dict[i])<<endl;
    }
}
int main(){
    vector<string> dict={"zibra","dog","duck","dove"};
    prefixproblem(dict);
    return 0;
}