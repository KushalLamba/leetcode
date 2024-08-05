#include <bits/stdc++.h>
using namespace std;
// int minDifficulty(vector<int> &jobDifficulty, int d, int pos = 0)
// {
//     int ans = INT_MAX;
//     int n = jobDifficulty.size();
//     if (d == 1)
//     {
//         int maxi = 0;
//         for (int i = pos; i < n; i++)
//         {
//             maxi = max(maxi, jobDifficulty[i]);
//         }
//         return maxi;
//     }
//     int mxa=0;
//     for (int i = pos; i <=n-d; i++)
//     {
//         mxa = max(mxa, jobDifficulty[i]);
//         int value = minDifficulty(jobDifficulty, d-1,i+1);
//         if (value != INT_MAX)
//             ans = min(ans, mxa + value);
//     }
//     return ans;
// }
// bottom to up approch
int maxelement(vector<int>& nums,int pos)
{
    int maxi=INT_MIN;
    for(int i=pos;i<nums.size();i++)
    {
        maxi=max(nums[i],maxi);
    }
    return maxi;
}
int minDifficulty(vector<int> &jobdifficulty, int d)
{
    int n = jobdifficulty.size();
    vector<vector<int>> dp(n,vector<int>(d+1));
    if(d>n) return -1;
    for(int i=0;i<n;i++)
    {
        dp[i][1]=maxelement(jobdifficulty,i);
    }
    for(int day=2;day<=d;day++)
    {
        for(int i=0;i<=n-day;i++)
        {
            int maxd=INT_MIN;
            int result=INT_MAX;
            for(int j=i;j<=n-day;j++)
            {
                maxd=max(maxd,jobdifficulty[j]);
                result=min(result,maxd+dp[j+1][day-1]);
            }
            dp[i][day]=result;
        }
    }
    return dp[0][d];
}
int main()
{
    int n;
    cout << "Enter N: " << endl;
    cin >> n;
    vector<int> jobDifficulty(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jobDifficulty[i];
    }
    int d;
    cin >> d;
    cout << minDifficulty(jobDifficulty, d);
    return 0;
}