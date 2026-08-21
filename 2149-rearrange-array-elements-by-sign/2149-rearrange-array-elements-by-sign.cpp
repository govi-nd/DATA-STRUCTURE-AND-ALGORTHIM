class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;

        // vector<int> pos, neg;

        // for (int x : nums) {
        //     if (x > 0) pos.push_back(x);
        //     else neg.push_back(x);
        // }

        // int p = 0, q = 0;

        // for (int i = 0; i < nums.size(); i++) {
        //     if (i % 2 == 0)
        //         nums[i] = pos[p++];
        //     else
        //         nums[i] = neg[q++];
        // }

        // return nums;
    }
};