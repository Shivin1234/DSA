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
public:
    Node* head;
    Node* tail;

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
};
 void printlist(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
};
bool iscycle(Node* head){   //detecting a cycle
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;            //+1
            fast=fast->next->next;     //+2
            if(fast==slow){
                cout<<"cycle exist\n";
                return true;
            }
        }
        cout<<"cycle does not exist\n";
        return false;
};

void removecycle(Node* head){                              //removing the cycle from the linked list
    Node* slow=head;                                      //first we will detect the cycle
    Node* fast=head;                                     //after that we will asign slow=head
    bool iscycle=false;                                 //then slow+1 and fast+1   
    while(fast!=NULL && fast->next!=NULL){             //if slow=fast then fast->previous=NULL
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"cycle exist\n";
            iscycle=true;
            break;
        }
    }
    if(!iscycle){
        cout<<"cycle does not exist\n";
        return;
    }
    //if cycle exist then
    slow=head;
    if(slow==fast){            //special case where last node point to the first node
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;      //removed the cycle
    }
    else{
        Node* prev=fast;
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=NULL;   //removed the cycle
    }
};

int main(){
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next=ll.head;
    removecycle(ll.head);
    printlist(ll.head);
}