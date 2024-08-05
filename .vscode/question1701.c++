#include <bits/stdc++.h>
using namespace std;
double averageWaitingTime(vector<vector<int>> &customers)
{
    if (customers.size() == 0)
        return 0;
    int add = 0;
    int sum = 0;
    for (int i = 0; i < customers.size(); i++)
    {
        if (add >= customers[i][0])
        {
            add += customers[i][1];
            sum += add - customers[i][0];
        }
        else
        {
            add = customers[i][1] + customers[i][0];
            sum += add - customers[i][0];
        }
    }
    return (1.0 * sum) / customers.size();
}
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    vector<vector<int>> customers(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i][0];
        cin >> customers[i][1];
    }
    cout << averageWaitingTime(customers);
}