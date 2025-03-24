//checking if LL is palindrone or not
#include<iostream>
#include<string>
#include<list>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class List{
public:
    Node* head;
    Node* tail;

    List(){
        head=NULL;
        tail=NULL;
    }
};
bool ispalin(string str){
    int n=str.size();
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1]){
            return false;
        }
    }
    return true;
}

bool ispalindrome(Node* head){
    string str="";
    Node* temp=head;
    while(temp!=NULL){
        str+=temp->data;
        temp=temp->next;
    }
    return ispalin(str);
}

int main(){
    List ll;
    string str="1222213";
    cout<<ispalindrome(ll.head);
    return 0;
}
