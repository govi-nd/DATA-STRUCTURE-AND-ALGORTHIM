class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;

        for(auto ch : s) {
            if(st.empty()) {
                st.push(ch);
            }
            else if(st.top() != ch) {
                st.push(ch);
            }
            else {
                st.pop();
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};