class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());
        int ans = 0;
        for(int num : st){
            if(!st.count(num - 1)){
                int cur = num;
                int cnt = 1;
                while(st.count(cur+1)){
                    cnt++;
                    cur++;
                }
                ans = max(ans , cnt);
            }
        }
        return ans;
        
    }
};