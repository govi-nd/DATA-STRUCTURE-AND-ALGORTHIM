class Solution {
public:
    string encode(string str) {
        unordered_map<char, char> mp;
        char next = 'a';
        string ans;

        for (char c : str) {
            if (mp.find(c) == mp.end())
                mp[c] = next;
                next++;

            ans += mp[c];
        }

        return ans;
    }

    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }
};