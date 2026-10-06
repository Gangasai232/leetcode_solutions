class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int>st;
        st.push(0);
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int inner = st.top();
                st.pop();
                int val;
                if(inner == 0){
                    val = 1;
                }
                else val = 2*inner;
                st.top() += val;
            }
        }
        return st.top();
        
    }
};