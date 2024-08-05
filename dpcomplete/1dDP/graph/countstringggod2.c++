#include<bits/stdc++.h>
using namespace std;
int main()
{
    int high;
    cin>>high;
    int low;
    cin>>low;
    int zero=1,one=2;
    vector<int> dp(high+1,0);
    dp[zero]+=1;
    dp[one]+=1;
    int count=0;
    for(int i=0;i<=high;i++)
    {
        if(i-zero>=0)
        {
            dp[i]+=dp[i-zero];
        }
        if(i-one>=0)
        {
            dp[i]+=dp[i-one];
        }
        if(i>=low)
        {
            cout<<"hello"<<endl;
            count+=dp[i];
        }
    }
    cout<<count<<endl;
}