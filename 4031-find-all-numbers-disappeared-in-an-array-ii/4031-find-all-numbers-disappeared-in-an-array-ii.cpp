class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {

        vector<vector<int>> main;

        if (nums.empty()) {
            main.push_back({lower, upper});
            return main;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // Duplicate ko skip karo
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Current number range ke andar nahi hai
            if (nums[i] < lower)
                continue;

            if (nums[i] > upper)
                break;

            // lower se nums[i] - 1 tak missing range
            if (lower < nums[i]) {
                main.push_back({lower, nums[i] - 1});
            }

            lower = nums[i] + 1;
        }

        // Last missing range
        if (lower <= upper) {
            main.push_back({lower, upper});
        }

        return main;
    }
};