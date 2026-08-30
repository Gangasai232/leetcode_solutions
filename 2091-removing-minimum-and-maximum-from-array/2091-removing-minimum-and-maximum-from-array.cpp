class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxVal = INT_MIN;
        int maxi = 0;

        int minVal = INT_MAX;
        int mini = 0;

        for (int i = 0; i < n; i++) {

            if (maxVal < nums[i]) {
                maxVal = nums[i];
                maxi = i;
            }

            if (minVal > nums[i]) {
                minVal = nums[i];
                mini = i;
            }
        }

        int left = max(mini, maxi) + 1;

        int right = n - min(mini, maxi);

        int mixed = min(
            maxi + 1 + n - mini,
            mini + 1 + n - maxi
        );

        return min({left, right, mixed});
    }
};