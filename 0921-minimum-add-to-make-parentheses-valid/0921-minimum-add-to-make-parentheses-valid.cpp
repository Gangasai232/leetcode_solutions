class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int open = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                open++;
            }
            else{
                if(open > 0) open--;
                else ans++;
            }
        }
        return ans + open;
        
    }
};