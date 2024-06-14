#include <iostream>
#include <vector>
using namespace std;
int subarraysDivByK(vector<int> &nums, int k, int pos = 0, int sum = 0)
{
    if (pos == nums.size())
    {
        if (sum%k==0){
            cout<<sum<<endl;
            return 1;
        }
        return 0;
    }
    int ans = nums[pos];
    return subarraysDivByK(nums, k, pos + 1, sum) + subarraysDivByK(nums, k, pos + 1, sum + ans);
}
int main()
{
    cout << "Enter Number Of Elements:" << endl;
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Enter value of K: " << endl;
    int k;
    cin >> k;
    cout<<subarraysDivByK(nums,k);
}