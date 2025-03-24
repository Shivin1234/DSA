#include <iostream>
#include <string>
using namespace std;

class Teacher{
    public:
    string subject;
    float salary;
};
class Student{
    public:
    int rollno;
    float cgpa;
};
class TA:public Teacher,public Student{
    public:
    string name;
};
int main()
{
    TA t1;
    t1.name="Shivin";
    t1.subject="Python";
    t1.cgpa=9.5;
    t1.rollno=221069;
    cout<<t1.name<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.cgpa<<endl;
    cout<<t1.rollno<<endl;
     return 0;
}
