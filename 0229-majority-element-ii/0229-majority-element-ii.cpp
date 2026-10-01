class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = -100;
        int el2 = -1;
        int n = nums.size();
        vector<int>ans;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(cnt1 == 0 && nums[i] != el2){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && nums[i] != el1){
                el2 = nums[i];
                cnt2++;
            }
           else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
             
        }
        cnt1 = 0;
        cnt2 = 0;
        for(auto it : nums){
            if(it == el1) cnt1++;
            if(it == el2) cnt2++;
        }
        if(cnt1 > n/3) ans.push_back(el1);
        if(cnt2 > n/3) ans.push_back(el2);
        return ans;

    }
};