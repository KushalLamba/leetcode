#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    cout<<"Enter C: "<<endl;
    int c;
    cin>>c;
    int flag=0;
    int s=pow(c,0.5);
    int i=0;
    while(i<=s)
    {
        if(pow(i,2)+pow(s,2)<c) i++;
        else if(pow(i,2)+pow(s,2)>c) s--;
        else
        {
           cout<<true;
           break;
        }
    }
}