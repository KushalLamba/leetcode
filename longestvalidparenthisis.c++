#include <iostream>
#include<algorithm>
#include <stack>
using namespace std;
int longestValidParentheses(string s)
{
    if (s.empty())
    {
        return 0;
    }
    stack<int> st;
    int start = -1;
    int maxlen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (st.empty())
            {
                start = i;
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    maxlen = max(maxlen, i - start);
                }
                else
                    maxlen = max(maxlen, i - st.top());
            }
        }
    }
    return maxlen;
}
int main()
{
    cout << "Enter The string: " << endl;
    string s;
    cin >> s;
    int ans = longestValidParentheses(s);
    cout << endl;
    cout << ans;
}