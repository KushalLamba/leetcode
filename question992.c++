#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int atMostK(const vector<int>& nums, int k) {
    int start = 0;
    int end = 0;
    int distinctCount = 0;
    int result = 0;
    unordered_map<int, int> countMap;

    while (end < nums.size()) {
        // Increment the count of the current number
        countMap[nums[end]]++;
        // If this is the first occurrence of the number, increase distinct count
        if (countMap[nums[end]] == 1) {
            distinctCount++;
        }
        
        // Adjust the window if distinct count is more than k
        while (distinctCount > k) {
            countMap[nums[start]]--;
            if (countMap[nums[start]] == 0) {
                distinctCount--;
            }
            start++;
        }

        // All subarrays starting from `start` and ending at `end-1` have at most `k` distinct integers
        result += end - start + 1;
        end++;
    }
    return result;
}

int subarraysWithKDistinct(const vector<int>& nums, int k) {
    // The number of subarrays with exactly `k` distinct integers
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the value of K: ";
    cin >> k;
    
    int result = subarraysWithKDistinct(nums, k);
    cout << "Number of subarrays with exactly " << k << " distinct integers: " << result << endl;
    
    return 0;
}
