#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<double, int> a, pair<double, int> b)
{
    return a.first > b.first;
}
int main()
{
    int n;
    cout << "Enter No. of: " << endl;
    cin >> n;
    int *weight = new int[n];
    int *values = new int[n];
    int maxweight;
    cout << "Enter maximum weight: " << endl;
    cin >> maxweight;
    cout << "Enter All weights: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << "Enter All values: " << endl;
    for (int j = 0; j < n; j++)
    {
        cin >> values[j];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        double pair1 = (1.0 * values[i]) / weight[i];
        pair<double, int> p = make_pair(pair1, i);
        ans.push_back(p);
    }
    double finalprofit = 0;
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<maxweight<<" "<<finalprofit<<endl;
        if (maxweight < weight[ans[i].second])
        {
            
            finalprofit += (1.0)*maxweight * (1.0*values[ans[i].second]/weight[ans[i].second]);
            maxweight = 0;
        }
        else
        {
            finalprofit += (1.0)*values[ans[i].second];
            maxweight=maxweight-weight[ans[i].second];
        }
    }
    cout<<finalprofit;
}