class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {

            while (k > 0 && !st.empty() && st.top() > digit) {
                st.pop();
                k--;
            }

            st.push(digit);
        }

        // If k digits are still left, remove from the end
        while (k > 0) {
            st.pop();
            k--;
        }

        // Stack gives digits in reverse order
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};