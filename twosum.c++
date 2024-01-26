/*                            TWO SUM LEETCODE                                       */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int target;
    cout<<"Enter Target: "<<endl;
    cin>>target;
    vector<int> arr;
    vector<int> output;
    int data;
    cout<<"Enter Elements of Vector"<<endl;
    cin>>data;
    while(data!=-1)
    {                 
        arr.push_back(data);   // taking vector element 
        cin>>data;
    }
    unordered_map<int,int> seen;
    for(int i=0;i<arr.size();i++)
    {
        int ans=target-arr[i];
        if(seen.find(ans)!=seen.end())    // checking it is preesent in vector or not
        {
           output.push_back(seen[ans]);  // ham isma picha sa check kar raha hai dhayan rakhana
           output.push_back(i);   
           break;  
        }
        seen[arr[i]] = i;   //store element 
    }
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}