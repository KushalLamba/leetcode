/*                Question 22 Leetcode Generate Parenthisis                          */
// class Solution {
// public:
//     void findall(string current, int open, int close, vector<string>& output,
//                  int n) {
//         if (current.length() == 2 * n) {
//             output.push_back(current);
//         }
//         if (open < n) {
//             findall(current + "(", open + 1, close, output, n);
//         }
//         if (close < open) {
//             findall(current + ")", open, close + 1, output, n);
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         findall("(", 1, 0, result, n);
//         return result;
//     }