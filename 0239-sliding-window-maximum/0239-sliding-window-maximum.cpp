class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> q;
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // remove element out of the window
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // remove every smaller element less than current element to
            // maintain monotonicity
            while (!q.empty() && arr[q.back()] < arr[i]) {
                q.pop_back();
            }

            // Add current index
            q.push_back(i);

            // store ans for first window
            if (i >= k - 1) {
                ans.push_back(arr[q.front()]);
            }
        }
        return ans;
    }
};