#include<iostream>
#include<vector>
using namespace std;
vector<int> sol(vector<int> ans,int maxsum,int sum,int i)
{
    vector<int> output;
    if(i==ans.size())
    {
        if(sum==maxsum)
        {
            return output;
        }
    }
    vector<int> include=sol(ans,maxsum,sum+ans[i],i++);
    vector<int> exclude=sol(ans,maxsum,sum,i++);
}
int main()
{
    cout<<"Enter Number of Weigths: "<<endl;
    int n;
    cin>>n;
    int * arr=new int[n];
    cout<<"Enter Number Of Weights: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Max Weight: "<<endl;
    int maxw;
    cin>>maxw;


}