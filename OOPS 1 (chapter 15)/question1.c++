#include <iostream>
#include <string>
using namespace std;
class User{
private:
int id;
string password;

public:
    string username;
    User(int id){
        this->id=id;
    }

void setpassword(string password){
    this->password=password;
}
string getpassword(){
    return password;
}
};
int main()
{
    User u1(101);
    u1.username="Shivin Bassi";
    u1.setpassword("aBcD");

    cout<<"username is:"<<u1.username<<"\n";
    cout<<"password is:"<<u1.getpassword()<<"\n";
    return 0;
}
