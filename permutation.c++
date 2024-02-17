// class Solution {
// public:
//     vector<vector<int>> ans;
//     void helper(vector<int>& nums, vector<int>& temp, int start, int end) {
//         if (start == end) {
//             for (int i = 0; i < nums.size(); i++) {
//                 temp.push_back(nums[i]);
//             }
//             ans.push_back(temp);
//             for (int i = 0; i < nums.size(); i++) {
//                 temp.pop_back();
//             }
//             return;
//         }
//         for (int i = start; i <= end; i++) {
//             swap(nums[start], nums[i]);
//             helper(nums, temp, start + 1, end);
//             swap(nums[start], nums[i]);
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> temp;
//         helper(nums,temp,0,nums.size()-1);
//         return ans;
//     }
// };