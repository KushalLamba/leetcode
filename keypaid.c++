#include <iostream>
#include <vector>
using namespace std;

string giver(int x)
{
    vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return s[x];
}

vector<string> letterCombinations(int x)
{
    if (x == 0)
    {
        vector<string> output;
        output.push_back("");
        return output;
    }

    vector<string> output = letterCombinations(x / 10);
    string s = giver(x % 10);

    vector<string> newOutput; 

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            newOutput.push_back(output[i] + s[j]);
        }
    }
    return newOutput; 
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = letterCombinations(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
