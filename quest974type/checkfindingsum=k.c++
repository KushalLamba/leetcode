#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
    cout<<"Enter Number Of Elements in an array: "<<endl;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter Elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    
}