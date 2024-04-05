#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, Max = 0;
    cin >> n;
    vector<int> v(n);
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        Max = max(Max, v[i]);
    }
    queue<string> q;
    q.push("1");
    int i = 1;
    arr.push_back("1");
    while (!q.empty())
    {
        //  cout<<"TEST"<<Max;
         break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[v[i] - 1] << endl;
    }
}