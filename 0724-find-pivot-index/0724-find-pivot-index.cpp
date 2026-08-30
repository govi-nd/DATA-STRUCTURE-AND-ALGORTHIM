class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;

        int sumLeft = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sumRight = total - sumLeft - nums[i];
            if (sumLeft == sumRight) return i;
            sumLeft += nums[i];
        }
        return -1;
    }
};