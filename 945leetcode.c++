// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;
// int main()
// {
//     cout << "Enter Number Of Elements in an Array: " << endl;
//     int n;
//     cin >> n;
//     cout << "Enter Array: " << endl;
//     vector<int> num(n, 0);
//     unordered_map<int, bool> check;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> num[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (check.count(num[i]) == 0)
//             check[num[i]] = false;
//     }
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (check[num[i]] == true)
//         {

//             while (check.count(num[i]) > 0)
//             {
//                 cout << "incorrect" << endl;
//                 num[i]++;
//                 count++;
//             }
//             check[num[i]]=true;
//         }
//         else
//         {
//             cout << "correct" << endl;
//             check[num[i]] = true;
//         }
//     }
//     cout << "Answer is :" << count;
// }


//another appproch(best approch)



// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i - 1] >= nums[i]) {
//                 ans += nums[i - 1] - nums[i] + 1;
//                 nums[i] = nums[i - 1] + 1;
//             }
//         }
//         return ans;
//     }
// };