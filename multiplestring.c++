#include <iostream>
#include <algorithm>
long long int reverse(long long int n)
{
    long long int value;
    while (n != 0)
    {
        value = value * 10 + n % 10;
        n = n / 10;
    }
    return value;
}
using namespace std;
int main()
{
    cout << "Enter string 1: " << endl;
    string str1 = "9";
    cout << "Enter String 2: " << endl;
    string str2 = "99";
    int i = 0;
    long long int ans1 = 0, ans2 = 0;
    while (i < str1.length() && i < str2.length())
    {
        ans1 = ans1 * 10 + int(str1[i] - '0');
        ans2 = ans2 * 10 + int(str2[i] - '0');
        i++;
    }
    while (i < str1.length())
    {
        ans1 = ans1 * 10 + int(str1[i] - '0');
        i++;
    }
    while (i < str2.length())
    {
        ans2 = ans2 * 10 + int(str2[i] - '0');
        i++;
    }
    cout << ans1 << " " << ans2;
    // long long int n=ans1*ans2;
    // string ans="";
    // while(n!=0)
    // {
    //     ans+=char('0'+n%10);
    //     n=n/10;
    // }
    // reverse(ans.begin(),ans.end());
    // cout<<ans;
}