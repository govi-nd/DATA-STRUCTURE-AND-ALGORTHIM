class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> PSE = prevSmaller(arr);
        vector<int> NSE = nextSmaller(arr);

        long long ans = 0;
        long long MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - PSE[i];
            long long right = NSE[i] - i;

            ans = (ans + arr[i] * left * right) % MOD;
        }

        return ans;
    }
};