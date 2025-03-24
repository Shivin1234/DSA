#include <iostream>
#include <string>
using namespace std;
class Student{
    string name;
    float cgpa;

    public:
    int getpercentage(){
        cout<<(cgpa*10)<<endl;
    }

    //setters
    void setname(string nameval){
        name=nameval;
    }
    void setcgpa(float cgpaval){
        cgpa=cgpaval;
    }

    //getters
    string getname(){
        return name;
    }
    float getcgpa(){
        return cgpa;
    }

};
class User{
    int id;
    string username;
    string bio;
    string password;
    void deactivate(){
        cout<<"deleting account\n";
    }
    void editbio(string newbio){
        bio=newbio;
    }
};
int main(){ 
    Student s1;
    s1.setname("shivin");
    s1.setcgpa(9.08);
    cout<<s1.getname()<<"\n";
    cout<<s1.getcgpa()<<"\n";
    cout<<s1.getpercentage();
    return 0;
}