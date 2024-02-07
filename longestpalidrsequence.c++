// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//         vector<int> curr(s2.length() + 1, 0);
//         vector<int> next(s2.length() + 1, 0);
//         for (int i = s1.length() - 1; i >= 0; i--) {
//             for (int j = s2.length() - 1; j >= 0; j--) {
//                 int ans = 0;
//                 if (s1[i] == s2[j]) {
//                     ans = 1 + next[j + 1];
//                 } else {
//                     ans = max(next[j], curr[j + 1]);
//                 }
//                 curr[j] = ans;
//             }
//             next = curr;
//         }
//         return next[0];
//     }
//     int longestPalindromeSubseq(string s) {
//         string s2 = s;
//         reverse(s2.begin(), s2.end());
//         return longestCommonSubsequence(s, s2);
//     }
// };