int helper(string s, int l, int r,vector<vector<int>>& dp)
{
    if (l == r)
        return 1;
    if (l > r)
        return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    int i = l + 1;
    while (i <= r && s[i] == s[l])
        i++;
    if(i==r+1) return 1;
    ans1 = 1 + helper(s, i, r,dp);
    for (int j = i; j <= r; j++)
    {
        if (s[l] == s[j])
        {
            ans2 = helper(s, i, j - 1,dp) + helper(s, j, r,dp);
        }
    }
    return dp[l][r]=min(ans1, ans2);
}
int strangePrinter(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(s, 0, s.size() - 1,dp);
}