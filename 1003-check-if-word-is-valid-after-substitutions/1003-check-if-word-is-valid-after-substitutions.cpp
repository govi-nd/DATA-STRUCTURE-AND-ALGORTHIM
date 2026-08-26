class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto i : s) {
            st.push(i);

            if (st.top() == 'c') {
                st.pop();

                if (!st.empty() && st.top() == 'b') {
                    st.pop();

                    if (!st.empty() && st.top() == 'a') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};