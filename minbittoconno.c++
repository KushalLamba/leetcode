#include<iostream>
using namespace std;
int main()
{
    int start,goal;
    cin>>start>>goal;
    start=start^goal;
    int count=0;
    while(start!=0)
    {
        count++;
        start&=(start-1);
    }
    cout<<count<<endl;
}