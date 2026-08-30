class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0;
        int right = 1;
        int count = 0;

        while (right < n) {

            if (left == right) {
                right++;
                continue;
            }

            int diff = nums[right] - nums[left];

            if (diff < k) {
                right++;
            }
            else if (diff > k) {
                left++;
            }
            else {
                count++;

                // Skip duplicates
                int leftValue = nums[left];
                int rightValue = nums[right];

                while (left < n && nums[left] == leftValue)
                    left++;

                while (right < n && nums[right] == rightValue)
                    right++;
            }
        }

        return count;
    }
};