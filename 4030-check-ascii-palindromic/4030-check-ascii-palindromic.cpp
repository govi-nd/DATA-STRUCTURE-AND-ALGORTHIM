class Solution {
public:
    bool isPalindromic(string s) {
        string num;

        for (auto i : s) {
            int charToNumber = (int)i;
            num += bitset<8>(charToNumber).to_string();
        }

        string rev = num;
        reverse(rev.begin(), rev.end());

        return num == rev;
    }
};