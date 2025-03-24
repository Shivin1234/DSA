#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Student{          // "<" operator overloading
    public:
    string name;
    int marks;

    Student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }   
    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;  
    }
};
int main(){
    priority_queue<Student> pq;
    pq.push(Student("aman",80));
    pq.push(Student("shivin",98));
    pq.push(Student("naman",67));

    while(!pq.empty()){
        cout<<"top : "<<pq.top().name<<","<<pq.top().marks<<endl;
        pq.pop();
    }
    
     return 0;
}