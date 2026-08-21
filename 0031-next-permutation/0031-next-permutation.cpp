class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        // Step 1: Break point
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: No breakpoint
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};