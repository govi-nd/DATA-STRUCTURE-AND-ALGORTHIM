class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>> onesA, onesB;

        // Collect positions of 1s in both images
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1) onesA.push_back({r, c});
                if (img2[r][c] == 1) onesB.push_back({r, c});
            }
        }

        // For every pair (a from onesA, b from onesB),
        // compute the shift (dx, dy) that would align them, and vote for it
        unordered_map<int, int> votes; // encode (dx, dy) as a single int key

        int best = 0;
        for (auto& a : onesA) {
            for (auto& b : onesB) {
                int dx = b.first - a.first;
                int dy = b.second - a.second;

                // encode (dx, dy) uniquely: shift range is [-(n-1), n-1],
                // so offset by n to keep values non-negative, then flatten
                int key = (dx + n) * (2 * n + 1) + (dy + n);

                votes[key]++;
                best = max(best, votes[key]);
            }
        }

        // The shift with the most votes is the answer
        return best;
    }
};