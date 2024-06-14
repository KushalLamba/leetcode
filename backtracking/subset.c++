#include<iostream>
#include<vector>
using namespace std;
void printsubset(int i,int n,vector<int> set,vector<int>& subset,int taregtsum)
{
    if(taregtsum==0)
    {
        cout<<"[";
        for(int i=0;i<subset.size();i++)
        {
            cout<<subset[i]<<" ";
        }
        cout<<"] ";
        return;
    }
    if(i==n)
    {
        return;
    }
    printsubset(i+1,n,set,subset,taregtsum);
    if(set[i]<=taregtsum)
    {
        subset.push_back(set[i]);
        printsubset(i+1,n,set,subset,taregtsum-set[i]);
        subset.pop_back();
    }
}
int main()
{
    cout<<"Enter No Of Element: "<<endl;
    int n;
    cin>>n;
    vector<int> set(n,0);
    for(int i=0;i<set.size();i++)
    {
        cin>>set[i];
    }
    cout<<"Enter The TargetSum: "<<endl;
    int targetsum;
    cin>>targetsum;
    vector<int> subset;
    printsubset(0,n,set,subset,targetsum);
    return 0;
}