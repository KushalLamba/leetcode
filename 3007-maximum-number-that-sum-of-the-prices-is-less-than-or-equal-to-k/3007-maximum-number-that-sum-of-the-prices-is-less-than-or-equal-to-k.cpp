class Solution {
public:
    typedef long long ll;
    vector<ll> bitcount;
    void finder(ll n) {
        if (n == 0)
            return;
        if (n == 1) {
            bitcount[0] += 1;
            return;
        }
        if (n == 2) {
            bitcount[0] += 1;
            bitcount[1] += 1;
            return;
        }
        ll bitlength = log2(n);
        ll nearest = 1ll << bitlength;
        bitcount[bitlength] += n - nearest + 1;
        for (ll i = 0; i < bitlength; i++) {
            bitcount[i] += nearest / 2;
        }
        finder(n - nearest);
    }
    long long findMaximumNumber(long long k, int x) {
        ll left = 0;
        ll right = 1e15;
        ll ans = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            bitcount = vector<ll>(65, 0);
            finder(mid);
            ll sum = 0;
            for (ll i = 0; i < log2(mid) + 1; i++) {
                if ((i + 1) % x == 0)
                    sum += bitcount[i];
            }
            if (sum <= k) {
                left = mid + 1;
                ans = mid;
            } else
                right = mid - 1;
        }
        return ans;
    }
};