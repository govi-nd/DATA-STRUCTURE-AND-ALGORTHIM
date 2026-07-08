class Solution {
public:
    std::array<int,256> hash(string s){
        std::array<int,256>hash={0};
        for(int i = 0 ; i < s.size(); i++ ){
            hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,256>,vector<string>> mp ;
        for (auto str:strs){
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>> ans ;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
// class Solution {
// public:
//     array<int, 26> getHash(const string& s) {
//         array<int, 26> freq{};
//         for (char ch : s) {
//             freq[ch - 'a']++;
//         }
//         return freq;
//     }

//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<array<int, 26>, vector<string>> mp;

//         for (const string& str : strs) {
//             mp[getHash(str)].push_back(str);

//         }

//         vector<vector<string>> ans;
//         ans.reserve(mp.size());

//         for (const auto& [key, group] : mp) {
//             ans.push_back(group);
//         }

//         return ans;
//     }
// };