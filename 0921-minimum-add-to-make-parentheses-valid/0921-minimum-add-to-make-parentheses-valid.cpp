class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) ans++;
                else st.pop();
            }
        }
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
        
        
    }
};