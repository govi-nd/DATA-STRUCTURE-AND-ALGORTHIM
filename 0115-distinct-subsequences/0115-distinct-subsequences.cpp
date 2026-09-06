// class Solution {
// public:

//     int solve(int i, int j, string &s, string &t) {

//         // t completely formed
//         if (j == t.size())
//             return 1;

//         // s finished but t is still remaining
//         if (i == s.size())
//             return 0;

//         if (s[i] == t[j]) {

//             // take + skip
//             return solve(i + 1, j + 1, s, t)
//                  + solve(i + 1, j, s, t);
//         }

//         // characters don't match -> only skip
//         return solve(i + 1, j, s, t);
//     }

//     int numDistinct(string s, string t) {
//         return solve(0, 0, s, t);
//     }
// };

class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, int j, string &s, string &t) {

        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {

            return dp[i][j] =
                solve(i + 1, j + 1, s, t)
              + solve(i + 1, j, s, t);

        }

        return dp[i][j] =
            solve(i + 1, j, s, t);
    }

    int numDistinct(string s, string t) {

        dp.assign(s.size(), vector<int>(t.size(), -1));

        return solve(0, 0, s, t);
    }
};