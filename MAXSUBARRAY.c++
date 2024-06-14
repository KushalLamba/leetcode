#include <iostream>
#include<climits>
#include <algorithm>
using namespace std;
int total(int *arr, int low, int mid, int high)
{
    int tempsum = 0;
    int leftcrosssum=INT_MIN;
    int rightcrosssum=INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        tempsum += arr[i];
        leftcrosssum = max(leftcrosssum, tempsum);
    }

    tempsum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        tempsum += arr[i];
        rightcrosssum = max(rightcrosssum, tempsum);
    }
    return leftcrosssum+rightcrosssum;
}
int maximumsum(int *arr, int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int maxsum=0;
    int sum=0;
    int leftsum = maximumsum(arr, low, mid);
    int rightsum = maximumsum(arr, mid + 1, high);
    int crosssum = total(arr, low, mid, high);
    sum=max(leftsum, max(rightsum, crosssum));
    if(sum>maxsum)
    {
        maxsum=sum;
    }
    return maxsum;
}
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    cout << "Enter Elements Of Array: " << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maximumsum(arr, 0, n - 1);
}
// kadanes's algorithm
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int ans = INT_MIN;
//         for (int i = 0; i < nums.size(); i++) {
//             sum = sum + nums[i];
//             ans = max(ans, sum);
//             if (sum < 0) {
//                 sum = 0;
//             }
//         }
//         return ans;
//     }
// };