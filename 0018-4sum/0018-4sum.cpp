class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++){
            if(i > 0  && nums[i] == nums[i-1]) continue;
            for(int j = i+1 ; j < n ; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int y = n-1;
                while(k < y){
                    long long  sum = (long long)nums[i] + nums[j] + nums[k] + nums[y];
                    if(target > sum) k++;
                    else if(target < sum) y--;
                    else{
                        vector<int>temp = {nums[i] , nums[j] , nums[k] , nums[y]};
                        k++;
                        y--;
                        ans.push_back(temp);
                        while(k < y && nums[k] == nums[k-1])k++;
                        while(k < y && nums[y] == nums[y+1]) y--;
                    }
                }
            }

        }
        return ans;
        
        
    }
};