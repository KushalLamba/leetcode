#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{

    string rev = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c >= 65 && c <= 90 || c >= 97 && c <= 122 || c >= 48 && c <= 57)
        {
            if (c >= 65 && c <= 90)
                rev.push_back(c + 32);
            else
                rev.push_back(c);
        }
    }
    string ne = rev;
    reverse(rev.begin(), rev.end());
    int i=1,j=1;
    int curr=0;
    int prev=0;
    int prev1=0,prev2=0;
    while(i<ne.size() && j<rev.size())
    {
        if(ne[i-1]==rev[j-1])
        {
            curr=prev+1;
            prev=curr;
            i++;
            j++;
        }
        else{
            curr=max(prev1,prev2);
            if(prev1>prev2)
            {
                prev1=curr;
                i++;
            }
            else{
                prev2=curr;
                j++;
            }
        }
    }
    return curr==(ne.size()-1);
}
int main()
{
    cout<<"Enter String: "<<endl;
    string s;
    getline(cin,s);
    isPalindrome(s);
}