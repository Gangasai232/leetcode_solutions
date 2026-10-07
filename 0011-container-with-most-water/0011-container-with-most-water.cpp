class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MIN;
        while(low < high){
            int width = high - low;
            int height = min(nums[low] , nums[high]);
            ans = max(ans , width * height);
            if(nums[low] < nums[high]) low++;
            else high --;
        }
        return ans;
        
    }
};