class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Prefix sum 0 occurs once before starting
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int num : nums) {
            sum += num;

            // We need an earlier prefix sum = sum - k
            if (mp.count(sum - k)) {
                ans += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return ans;
    }
};