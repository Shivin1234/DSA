#include <iostream>
using namespace std;
class Complex{
    int real;
    int img;
    public:
        Complex(int r,int i){
            real=r;
            img=i;
        }
        void show(){
            cout<<real<<"-"<<img<<"i"<<endl;
        }
        Complex operator -(Complex &c2){
            int resreal=this->real-c2.real;
            int resimg=this->img-c2.img;
            Complex c3(resreal,resimg);
            return c3;
        }
        
};
int main()
{
    Complex c1(5,8);
    Complex c2(7,2);
    c1.show();
    c2.show();
    Complex c3=(c1-c2);
    c3.show();
    return 0;
}
