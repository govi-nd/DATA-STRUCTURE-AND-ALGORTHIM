class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        int l = 0, r = 0;
        int maxLen = 0;

        while (r < n) {
            mp[s[r]]++;

            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};