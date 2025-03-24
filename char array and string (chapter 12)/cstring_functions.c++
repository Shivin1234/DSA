#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[100];
    char str2[100]="shivin bassi";
    strcpy(str1,str2);
    cout<<str1<<endl;
    char str3[100]="hello ";
    char str4[100]="world";
    strcat(str3,str4);
    cout<<str3<<endl;
    char str5[100]="abc";
    char str6[100]="xyz";
    cout<<strcmp(str5,str6);
    return 0;
}
