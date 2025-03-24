#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }

    ~Node(){
        if (next!=NULL){
            delete next;
        }
    }
};

class HashTable{
    int totsize;
    int currsize;
    Node** table;

    int HashFunction(string key){
        int idx=0;

        for(int i=0;i<key.size();i++){
            idx=idx + (key[i] * key[i])%totsize;
        }
        return idx;
    }
    void rehash(){
        Node** oldTable=table;
        int oldSize=totsize;

        totsize=2*totsize;
        table=new Node*[totsize];

        for(int i=0;i<totsize;i++){
            table[i]=NULL;
        }

        for(int i=0;i<oldSize;i++){
            Node* temp= oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

    public:
        HashTable(int size=5){
            totsize=size;
            currsize=0;

            table=new Node*[totsize];

            for(int i=0;i<totsize;i++){
                table[i]=NULL;
            }
        }
        void insert(string key,int val){
            int idx=HashFunction(key);

            Node* newNode=new Node(key,val);
            Node* head=table[idx];

            newNode->next=table[idx];
            table[idx]=newNode;

            currsize++;

            double lambda=currsize/(double)totsize;
            if(lambda>1){
                rehash();
            }
        }

        bool exists(string key){
            int idx=HashFunction(key);

            Node* temp=table[idx];
            while(temp!=NULL){
                if(temp->key==key){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }

        int search(string key){
            int idx=HashFunction(key);

            Node* temp=table[idx];
            while(temp!=NULL){
                if(temp->key==key){
                    return temp->val;
                }
                temp=temp->next;
            }
            return -1;
        }
};
        void remove(string key){

        }
int main(){
    HashTable ht;

    ht.insert("india",150);
    ht.insert("china",150);
    ht.insert("us",50);
    ht.insert("nepal",10);
    ht.insert("uk",20);

    if(ht.exists("india")){
        cout<<"india population : "<<ht.search("india")<<endl;
    }
    return 0;
}