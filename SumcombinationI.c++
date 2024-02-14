// class Solution {
// public:
//     vector<vector<int>> ans;
//     void helper(vector<int>& candidates, int start, int target,
//                 vector<int>& temp) {
//         if (target == 0) {
//             ans.push_back(temp);
//             return;
//         }
//         for (int i = start; i < candidates.size(); i++) {
//             if (candidates[i] <= target) {
//                 temp.push_back(candidates[i]);
//                 helper(candidates, i, target - candidates[i], temp);
//                 temp.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> temp;
//         helper(candidates, 0, target, temp);
//         return ans;
//     }
// };