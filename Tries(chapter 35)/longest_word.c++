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
        void longesthelper(Node* root,string &ans,string temp){
            for(pair<char,Node*> child : root->children){
                if(child.second->endofword){
                    temp+=child.first;

                    if((temp.size()==ans.size()) && temp < ans || (temp.size() > ans.size())){
                        ans=temp;
                    }
                    longesthelper(child.second,ans,temp);
                        temp=temp.substr(0,temp.size()-1);
                }
            }
        }
        string longeststringwitheof(){
            string ans="";
            longesthelper(root,ans,"");
            return ans;
        }
    };

    string longeststring(vector<string> dict){
        Trie trie;

        for(int i=0;i<dict.size();i++){
            trie.insert(dict[i]);
        }
        return trie.longeststringwitheof();
    }

    int main(){
        vector<string> dict={"a","banana","app","appl","ap","apply","apple"};
        cout<<longeststring(dict)<<endl;
    }