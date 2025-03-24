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
        bool startswith(string prefix){
            Node* temp=root;

            for(int i=0;i<prefix.size();i++){
                if(temp->children[prefix[i]]){
                    temp=temp->children[prefix[i]];
                }else{
                    return false;
                }
            }
            return true;
        }
    };
        int main(){
            vector<string> words={"apple","app","mango","man","women"};
            Trie trie;
            for(int i=0;i<words.size();i++){
                trie.insert(words[i]);
            }
            cout<<trie.startswith("app");
            return 0;
        }
