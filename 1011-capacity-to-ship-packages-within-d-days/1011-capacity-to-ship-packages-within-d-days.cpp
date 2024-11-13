class Solution {
public:
    bool check(vector<int>& weights, int day, int mid) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                day--;
                sum = weights[i];
                if (day < 0)
                    return false;
            }
        }
        if (day <= 0)
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int first = *max_element(weights.begin(), weights.end());
        int last = first * weights.size();
        int ans = 0;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (check(weights, days, mid)) {
                ans = mid;
                last = mid - 1;
            } else
                first = mid + 1;
        }
        return ans;
    }
};