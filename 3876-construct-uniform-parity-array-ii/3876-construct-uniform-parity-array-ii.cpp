class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false, hasEven = false;
        int minOdd = INT_MAX, minEven = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0) {
                hasEven = true;
                minEven = min(minEven, x);
            } else {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }

        // Already uniform (all even or all odd)
        if (!hasOdd || !hasEven) return true;

        // Mixed: the smallest odd must be able to "unlock" every even element
        return minOdd < minEven;
    }
};