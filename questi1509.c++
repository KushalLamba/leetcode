// int minDifference(vector<int>& nums) {
//         if (nums.size() <= 4)
//             return 0;
//         sort(nums.begin(), nums.end());
//         int i = 0, j = nums.size() - 1;
//         for (int p = 3; p > 0; p--) {
//             int front = nums[j - p] - nums[i];
//             int back = nums[j] - nums[i + p];
//             if (front < back)
//                 j -= 1;
//             else
//                 i += 1;
//         }
//         return nums[j] - nums[i];
//     }