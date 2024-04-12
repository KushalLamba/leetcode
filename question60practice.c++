#include <iostream>
#include <vector>
using namespace std;

string ans1(vector<char> ans, int k, vector<bool>& visited, string& result, int& count, string s = "")
{
    if (s.size() == ans.size())
    {
        count++;
        if (count == k)
        {
            result = s;
            return result;
        }
        return "";
    }
    for (int j = 0; j < ans.size(); j++)
    {
        if (!visited[j])
        {
            s += ans[j];
            visited[j] = true;
            ans1(ans, k, visited, result, count, s);
            if (!result.empty()) return result;
            visited[j] = false;
            s.pop_back();
        }
    }
    return "";
}

string getPermutation(int n, int k)
{
    vector<char> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(char('0' + i));
    }
    vector<bool> visited(ans.size(), false);
    string result;
    int count = 0;
    ans1(ans, k, visited, result, count);
    return result;
}

int main()
{
    cout << "Enter the number: " << endl;
    int n;
    cin >> n;
    cout << "Enter Position: " << endl;
    int k;
    cin >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}
