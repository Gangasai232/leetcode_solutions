class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < target) smaller ++;
            if(nums[i] == target) cnt++;
        }
        vector<int>ans;
        for(int i = smaller ; i < smaller + cnt ; i++){
             ans.push_back(i);
        }
        return ans;
    }
};