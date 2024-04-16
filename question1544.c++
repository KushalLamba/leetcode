#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        int flag = 0;
        int A = s[i] - 64;
        if (i - 1 > 0)
        {
            if (s[i - 1] - 64 != A)
            {
                flag = 1;
            }
        }
        if (flag != 1 && i + 1 < s.size())
        {
            if (s[i + 1] - 64 != A)
            {
                ans.push_back(s[i]);
            }
        }
    }
    cout<<ans;
}