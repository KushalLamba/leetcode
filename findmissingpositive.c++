// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         if (nums.size() == 0) {
//             return 1;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] <= 0) {
//                 nums[i] = nums.size() + 1;
//             }
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             int index = abs(nums[i]) - 1;
//             if (index < nums.size() && nums[index] > 0) {
//                 nums[index] *= -1;
//             }
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > 0) {
//                 return i + 1;
//             }
//         }
//         return nums.size() + 1;
//     }
// };