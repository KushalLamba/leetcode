#include <iostream>
#include <vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sol = 0;
    int prev = 0;
    int total = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        total += gas[i] - cost[i];
        prev += gas[i] - cost[i];
        if (prev < 0)
        {
            prev = 0;
            sol = i + 1;
        }
    }
    return total < 0 ? -1 : sol;
}
int main()
{
    cout << "Enter Number Of Gas Station: " << endl;
    int n;
    cin >> n;
    vector<int> gases(n);
    vector<int> costs(n);
    cout << "Enter Gases and costs: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> gases[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }
    cout << canCompleteCircuit(gases, costs);
}