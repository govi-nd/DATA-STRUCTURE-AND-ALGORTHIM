class Solution {
public:
    int beautySum(string s) {
        // unordered_map<char, int> mp;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0)
                        continue;

                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }

                ans += mx - mn;
            }
        }
        // for (int i = 0; i < s.size(); i++) {
        //     mp.clear();
        //     for (int j = i; j < s.size(); j++) {
        //         char& ch = s[j];
        //         mp[ch]++;
        //         int maxi = INT_MIN;
        //         int mini = INT_MAX;
        //         for (auto it : mp) {
        //             maxi = max(maxi, it.second);
        //             mini = min(mini, it.second);
        //         }
        //         int sum = maxi - mini;
        //         beautySum += sum;
        //     }
        // }
        return ans;
    }
};