#include<iostream>
#include<vector>
using namespace std;
int maxvalue(vector<int> bloomday)
{
    int maxelement=0;
    for(int i=0;i<bloomday.size();i++) maxelement=max(maxelement,bloomday[i]);
    return maxelement;
}
bool validdays(vector<int> bloomdays,int m,int k,int days)
{
    int boque=0;
    int flower=0;
    for(int i=0;i<bloomdays.size();i++)
    {
        if(bloomdays[i]<=days)
        {
            flower++;
            if(flower==k)
            {
                boque++;
                flower=0;
                if(boque==m) return true;
            }
        }
        else flower=0;
    }
    return boque>=m;
}
int minDays(vector<int> bloomDay,int m,int k)
{
    if(m*k>bloomDay.size()) return -1;
    int left=1;
    int right=maxvalue(bloomDay);
    while(left<right)
    {
        int mid=left+((right-left)/2);
        if(validdays(bloomDay,m,k,mid))
        {
            right=mid;
        }
        else left=mid+1;
    }
    return left;
}
int main()
{
    cout<<"Enter No of Elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter Array of BloomDay: "<<endl;
    vector<int> bloomday(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>bloomday[i];
    }
    cout<<"Enter Value Of M: "<<endl;
    int m;
    cin>>m;
    cout<<"Enter Value Of K: "<<endl;
    int k;
    cin>>k;
    cout<<minDays(bloomday,m,k);
}