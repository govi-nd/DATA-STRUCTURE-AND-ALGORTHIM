class Solution {
public:
    int beautySum(string s) {
        unordered_map<char, int> mp;
        int beautySum = 0;
        for (int i = 0; i < s.size(); i++) {
            mp.clear();
            for (int j = i; j < s.size(); j++) {
                char& ch = s[j];
                mp[ch]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for (auto it : mp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                int sum = maxi - mini;
                beautySum += sum;
            }
        }
        return beautySum;
    }
};