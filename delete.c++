#include <iostream>
#include <vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int sum = 1;
    int start = 0;
    int end = 0;
    int count=0;
    while (end < nums.size())
    {
        sum = sum * nums[end];
        if (sum < k)
        {
            count++;
            end++;
        }
        else
        {
            sum = sum / nums[start];
            if(sum<k) count++;
            start++;
        }
    }
    while(start!=end)
    {
        sum=sum/nums[start];
        if(nums[start]<k)
        {
            count++;
        }
        if(sum<k) count++;
        start++;
    }
    return count;
}
int main()
{
    cout << "Enter Number of Elements: " << endl;
    int n;
    cin>>n;
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout<<"Enter Value of k: "<<endl;
    int k;
    cin>>k;
    cout<<numSubarrayProductLessThanK(value,k);
    return 0;
}