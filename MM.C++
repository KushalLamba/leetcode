#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int mm(int *arr,int i,int j,vector<vector<int>> dp)
{
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j]=min(dp[i][j],mm(arr,i,k,dp)+mm(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j];
}
int main()
{
    cout<<"Enter Number Of Elements: "<<endl;
    int n;
    cin>>n;
    int *arr=new int[n];
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<mm(arr,1,n-1,dp);
}