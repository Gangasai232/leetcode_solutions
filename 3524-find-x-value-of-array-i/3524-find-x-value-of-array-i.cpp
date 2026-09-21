
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (long long x : nums) {
            vector<long long> ndp(k, 0);

            // Start a new subarray containing only x
            ndp[x % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRem = (r * (x % k)) % k;
                    ndp[newRem] += dp[r];
                }
            }

            dp = ndp;

            // Add all subarrays ending at current position
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};