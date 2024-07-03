#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char *ptr=new char[5];
    ptr[0]='u';
    strcpy(ptr,"hey");
    for(int i=0;i<2;i++)
    {
        cout<<ptr[i]<<endl;
    }
}