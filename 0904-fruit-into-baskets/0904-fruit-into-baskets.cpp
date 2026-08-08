class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> freq;

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {

            // Add current fruit
            freq[fruits[r]]++;

            // More than 2 different fruits
            while (freq.size() > 2) {

                freq[fruits[l]]--;

                // If frequency becomes 0, remove the key
                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]);
                }

                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};