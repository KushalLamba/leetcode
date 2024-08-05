#include <bits/stdc++.h>
using namespace std;
int finder(vector<vector<int>> &combined, int start, int value)
{
    int n = combined.size() - 1;
    int result = 0;
    while (start <= n)
    {
        int mid = (start + (n - start) / 2);
        if (value <= combined[mid][0])
        {
            result = mid;
            n = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
int jobScheduling(vector<vector<int>> &combined, int pos)
{
    if (pos >= combined.size())
    {
        return 0;
    }
    int nextindex = finder(combined, pos + 1, combined[pos][1]);
    int include = combined[pos][2] + jobScheduling(combined, nextindex);
    int exclude = jobScheduling(combined, pos + 1);
    return max(exclude, include);
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
    vector<vector<int>> combined(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        combined[i][0] = starttime[i];
        combined[i][1] = endtime[i];
        combined[i][2] = profit[i];
    }
    sort(combined.begin(), combined.end());
    cout << jobScheduling(combined,0);
}