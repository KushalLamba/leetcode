#include<iostream>
#include<vector>
using namespace std;
void printanswer(vector<int> s,vector<int>f)
{
    if(s.size()==0) return ;
    int i=0;
    cout<<"Answers are: "<<endl;
    cout<<i<<" ";
    for(int j=1;j<s.size();j++)
    {
        if(f[i]<s[j])
        {
            cout<<j<<" ";
            i=j;
        }
    }
    return;
}
int main()
{
    cout<<"Enter Number Of Activity"<<endl;
    int n;
    cin>>n;
    vector<int> s(n,0);
    vector<int> f(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    printanswer(s,f);
}