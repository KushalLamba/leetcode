#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& piles,int start,int end)
{
    if(start>=end) return 0;
    return max(piles[start]-helper(piles,start+1,end-1),piles[end]-helper(piles,start,end-1));
}
bool stoneGame(vector<int>& piles)
{
    int n=piles.size();
    return helper(piles,0,n-1)>0;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<stoneGame(nums);
}