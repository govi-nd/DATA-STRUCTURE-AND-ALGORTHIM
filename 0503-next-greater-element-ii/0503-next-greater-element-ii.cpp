class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = 2 * n - 1; i >= 0; i--) {
            int element = nums[i % n];

            while (!s.empty() && s.top() <= element)
                s.pop();

            if (i < n) {
                if (s.empty())
                    ans[i] = -1;
                else
                    ans[i] = s.top();
            }

            s.push(element);
        }

        return ans;
    }
};