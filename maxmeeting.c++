#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int maxEvents(vector<vector<int>> &events)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < events.size(); i++)
    {
        pair<int, int> p = make_pair(events[i][0], events[i][1]);
        ans.push_back(p);
    }
    sort(ans.begin(), ans.end(), cmp);

    int count = 0;
    vector<bool> chosen(events.size() + 1, false);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = ans[i].first; j <= ans[i].second; j++)
        {
            if (!chosen[j])
            {
                chosen[j] = true;
                count++;
                break;
            }
        }
    }

    return count;
}

int main()
{
    cout << "Enter Number of events: " << endl;
    int n;
    cin >> n;

    vector<vector<int>> events(n, vector<int>(2, 0));
    cout << "Enter start and end times for each event:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> events[i][0] >> events[i][1];
    }

    cout << "Maximum number of events that can be attended: " << maxEvents(events) << endl;
    return 0;
}
