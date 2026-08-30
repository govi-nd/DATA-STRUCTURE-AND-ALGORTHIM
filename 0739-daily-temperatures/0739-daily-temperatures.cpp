class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> s;
        vector<int> ans;

        for (int i = temperatures.size() - 1; i >= 0; i--) {

            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            if (s.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top() - i);
            }

            s.push(i);
        }

        reverse(ans.begin(), ans.end());

        // Convert -1 to 0
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == -1) {
                ans[i] = 0;
            }
        }

        return ans;
    }
};
































// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> s;
//         vector<int> ans;
//         for (int i = temperatures.size() - 1; i >= 0; i--) {
//             while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
//                 s.pop();
//             }
//             if (s.empty()) {
//                 ans.push_back(-1);
//             } else {
//                 ans.push_back(s.top());
//             }

//             s.push(i);
//         }
//         reverse(ans.begin(),ans.end());

//         for (int i = 0; i < ans.size(); i++) {
//             if (ans[i] == -1) {
//                 ans[i] = 0;
//             } else {
//                 int index = ans[i];
//                 int days = index - i;
//                 ans[i] = days;
//             }
//         }
//         return ans;
//     }
// };