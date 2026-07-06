// class Solution {
// public:
//     int romanToInt(string s) {
//         int res=0;
//         unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
//                                           {'L', 50},  {'C', 100}, {'D', 500},
//                                           {'M', 1000}};
//         for (int i = 0; i < s.size() - 1; i++) {
//             if (roman[s[i]] < roman[s[i + 1]]) {
//                 res = res - roman[s[i]];
//             } else {
//                 res = res + roman[s[i]];
//             }
//         }
//         return res+roman[s.back()];
//     }
// };
class Solution {
public:
    int value(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int ans = 0;
        int prev = value(s[0]);

        for (int i = 1; i < s.size(); i++) {
            int curr = value(s[i]);

            if (prev < curr)
                ans -= prev;
            else
                ans += prev;

            prev = curr;
        }

        return ans + prev;
    }
};