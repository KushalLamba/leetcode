#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight,vector<int> value,int maxweight,int start)
{
    if(maxweight<=0) return 0;
    int maxvalue=0;
    for(int i=start;i<weight.size();i++)
    {
        if(maxweight-weight[i]>=0)
        {
        int value1=knapsack(weight,value,maxweight-weight[i],i+1)+value[i];
        maxvalue=max(value1,maxvalue);
        }
    }
    return maxvalue;
}
int main()
{
    cout << "Enter number of elements: " << endl;
    int n;
    cin >> n;
    cout << "Enter weight and value of an element: " << endl;
    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    cout<<"Enter maxweight: "<<endl;
    int maxweight;
    cin>>maxweight;
    cout<<knapsack(weight,value,maxweight,0);
    return 0;
 }