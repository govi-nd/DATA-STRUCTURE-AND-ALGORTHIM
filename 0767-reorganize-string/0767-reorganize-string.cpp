class Solution {
public:
    string reorganizeString(string s) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int maxFreq = 0;
        int maxChar = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        int n = s.length();

        if (maxFreq > (n + 1) / 2)
            return "";

        string ans(n, ' ');

        int index = 0;

        // Fill the most frequent character at even indices
        while (freq[maxChar] > 0) {
            ans[index] = maxChar + 'a';
            index += 2;
            freq[maxChar]--;
        }

        // Fill remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {

                if (index >= n)
                    index = 1;

                ans[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }

        return ans;
    }
};