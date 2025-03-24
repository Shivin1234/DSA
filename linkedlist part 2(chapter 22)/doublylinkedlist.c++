#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        prev=next=NULL;
    }
};
class Doublyll{
    public:
    Node* head;
    Node* tail;

    Doublyll(){
        head=tail=NULL;
}
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
}
    void pop_front(){
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
            }
            temp->next=NULL;
            delete temp;
    }
    void printlist(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

};
int main(){
    Doublyll dbll;
    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printlist();
    dbll.pop_front();
    dbll.printlist();
    return 0;
}