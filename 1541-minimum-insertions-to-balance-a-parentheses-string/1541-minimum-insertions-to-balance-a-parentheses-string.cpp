class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                open++;
            }
            else{
                if(i+1 < n && s[i+1] == ')'){
                    i++;
                }
                else{
                    cnt++;
                }
                if(open > 0){
                    open--;
                }
                else{
                    cnt++;
                }
            }
        }
        cnt += 2*open;
        return cnt;
        
    }
};