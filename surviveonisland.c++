#include<iostream>
using namespace std;
int main()
{
    int N,M,S;
    cout<<"Enter Maximum food we purchase: "<<endl;
    cin>>N;
    cout<<"Enter Maximum food need to Survive: "<<endl;
    cin>>M;
    cout<<"Enter Maximum number of days to Survive: "<<endl;
    cin>>S;
    int sunday=S/7;
    int buyingdays=S-sunday;
    if(M<N)
    {
        return -1;
    }
    if(M==N)
    {
        if(S>buyingdays)
        {
            return -1;
        }
    }
    if((M*S)%N==0)
    {
        return (M*S)/N;
    }
    else{
        return (M*S)/N+1;
    }
    return 0;
}