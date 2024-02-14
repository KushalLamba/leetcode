// class Solution {
// public:
//     vector<vector<int>> ans;

//     void helper(vector<int>& candidates, int start, int target, vector<int>& temp, unordered_map<int, bool>& seen) {
//         if (target == 0) {
//             ans.push_back(temp);
//             return;
//         }

//         for (int i = start; i < candidates.size(); ++i) {
//             if (candidates[i] <= target && (i == start || candidates[i] != candidates[i - 1] || seen[candidates[i - 1]])) {
//                 temp.push_back(candidates[i]);
//                 seen[candidates[i]] = true;
//                 helper(candidates, i + 1, target - candidates[i], temp, seen);
//                 temp.pop_back();
//                 seen[candidates[i]] = false;
//             }
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int> temp;
//         unordered_map<int, bool> seen;
//         sort(candidates.begin(), candidates.end());
//         helper(candidates, 0, target, temp, seen);
//         return ans;
//     }
// };
// (i == start || candidates[i] != candidates[i - 1] || seen[candidates[i - 1]]
// THIS CONDITION IS VERY IMPORTANT PLEASE USE IN ANOTHER QUESTIONS ALSO
// i==start ka matlab hai ki phela hai to sidha insert kar denga
// candidates[i]!=candidtaes[i-1] ka mtlab hai ki pichla element vo tha hi nhi to ssame to banaga nhi
// seen[candidates[i-1]] check isliy akra ki agra vo bhi liya hai to dono to ak sath la sakta hai per alag alag nhi
//