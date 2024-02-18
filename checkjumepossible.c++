// class Solution {
// public:
//     int helper(vector<int>& nums, int i = 0) {
//         if (i >= nums.size() - 1) {
//             return 0;
//         }
//         if (nums[i] == 0) {
//             return INT_MAX;
//         }

//         int nextMaxIndex = i + 1;
//         for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
//             if (nums[nextMaxIndex] + nextMaxIndex <= nums[i + j] + i + j || i+j==nums.size()-1) {
//                 nextMaxIndex = i + j;
//             }
//         }

//         return 1 + helper(nums, nextMaxIndex);
//     }
//     int jump(vector<int>& nums) {
//         int ans = helper(nums);
//         if (ans == INT_MAX) {
//             return 0;
//         } else {
//             return ans;
//         }
//     }
// };