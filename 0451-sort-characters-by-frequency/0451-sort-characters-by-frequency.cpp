class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Count frequencies
        for (char ch : s) {
            mp[ch]++;
        }

        // Store in vector
        vector<pair<char, int>> freq(mp.begin(), mp.end());

        // Sort by frequency (descending)
        sort(freq.begin(), freq.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        // Build answer
        string ans;

        for (auto &p : freq) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};