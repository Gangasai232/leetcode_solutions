
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int smaller = INT_MAX;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            smaller = min(smaller, nums[i]);
            sum += nums[i];
        }

        return sum - (nums.size() * smaller);
    }
};
