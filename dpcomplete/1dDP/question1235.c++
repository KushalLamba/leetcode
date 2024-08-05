#include <bits/stdc++.h>
using namespace std;
int jobScheduling(vector<int> &starttime, vector<int> &endtime, vector<int> &profit, int pos, int prev)
{
    if (pos == starttime.size())
    {
        return 0;
    }
    int include = 0;
    int exclude = 0;
    if (prev == -1 || endtime[prev] <= starttime[pos])
    {
        exclude = jobScheduling(starttime, endtime, profit, pos + 1, prev);
        include = profit[pos] + jobScheduling(starttime, endtime, profit, pos + 1, pos);
    }
    exclude = jobScheduling(starttime, endtime, profit, pos + 1, prev);
    return max(include, exclude);
}
int main()
{
    int n;
    cin >> n;
    vector<int> starttime(n, 0);
    vector<int> endtime(n, 0);
    vector<int> profit(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> starttime[i];
        cin >> endtime[i];
        cin >> profit[i];
    }
    vector<vector<int>> combined(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        combined[i][0] = starttime[i];
        combined[i][1] = endtime[i];
        combined[i][2] = profit[i];
    }
    sort(combined.begin(), combined.end());
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<combined[i][0]<<" ";
        cout<<combined[i][1]<<" ";
        cout<<combined[i][2]<<endl;
    }
    // cout<<jobScheduling(starttime,endtime,profit,0,-1);
}