#include<iostream>
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
    Node* head;
    Node* tail;

public:
    List(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newnode=new Node(val);

        if(tail==NULL){
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }

    void push_back(int val){
        Node* newnode=new Node(val);

        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void printlist(){
        Node *temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    void insert(int val,int pos){
        Node* newnode=new Node(val);

        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"position is invalid\n";
                return;
            }
            temp=temp->next;
        }

        newnode->next=temp->next;
        temp->next=newnode;
}
    void pop_front(){
        if(head==NULL){
            cout<<"ll is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node* temp=head;

        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    int search(int key){   //linear search in a linkedlist
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                    return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node* temp,int key){   //recursive search in a linklist
        if(temp==NULL){
            return -1;
        }
        if(temp->data==key){
            return 0;
        }
        int idx=helper(temp->next,key);
        if(idx==-1){
            return -1;
        }
        else{
            return idx+1;
        }
    }
    int searchrecursive(int key){
         return helper(head,key);
    }
    void reverse(){                     //reverse a linked list
        Node* curr=head;
        Node* prev=NULL;

        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        head=prev;
    }
    int getsize(){      //remove Nth element from the link list
        int sz=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n){
        Node* prev=head;
        int size=getsize();
        for(int i=1;i<(size-n);i++){
            prev=prev->next;
        }
        Node* toDel=prev->next;
        cout<<"going to delete:"<<toDel->data<<endl;
        prev->next=prev->next->next;
    }

};
int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlist();

    ll.push_back(4);
    ll.push_back(5);
    ll.printlist();
    cout<<ll.search(4)<<endl;
    cout<<ll.searchrecursive(3)<<endl;

    ll.insert(100,2);
    ll.printlist();

    ll.pop_front();
    ll.printlist();

    ll.pop_back();
    ll.printlist();

    ll.reverse();
    ll.printlist();

    ll.removeNth(2);
    ll.printlist();

    return 0;
}
    
 
