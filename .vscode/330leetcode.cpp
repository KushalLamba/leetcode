#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter Number of Elements: " << endl;
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < nums.size(); i++)  cin >> nums[i];
    cout<<"Enter Value Of K: "<<endl;
    int k;
    cin>>k;
    int sum=0;
    int j=0;
    int i=0;
    int count=0;
    while(i<=k)
    {
        if(sum>=i) i++;
        else if(nums[j]<=i && nums[j]+sum>=i)
        {
            i+=sum+nums[j];
            sum+=nums[j];
            j++;
        }
        else 
        {
            nums.push_back(i);
            sum+=i;
            i++;
            count++;
        }
    }
    cout<<count;
}