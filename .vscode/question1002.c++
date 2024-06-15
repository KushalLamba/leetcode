#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<string> commonChars(vector<string>& words)
{
    vector<string> ans;
    if(words.size()==0) return ans;
    for(char c='a';c<='z';c++)
    {
        int mincount=INT_MAX;
        for(int i=0;i<words.size();i++)
        {
            int count=0;
            for(int j=0;j<words[i].size();j++)
            {
                if(words[i][j]==c) count++;
            }
            mincount=min(count,mincount);
        }
        for(int k=0;k<mincount;k++)
        {
            ans.push_back(string(1,c));
        }
    }
    return ans;
}
int main()
{
    cout<<"Enter Number Of Strings: "<<endl;
    int n;
    cin>>n;
    vector<string> words(n,"");
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    } 
    vector<string> ans=commonChars(words);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    } 
}