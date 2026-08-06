class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int lsum = 0 , rsum = 0 , sum = 0 , maxSum = 0 , n = nums.size() , rindex = n-1 ;
        for( int i = 0 ; i <= k-1 ; i++){
            lsum += nums[i];
        }
        maxSum = lsum ;
        for( int i = k-1 ; i >= 0 ; i--){
            lsum-=nums[i];
            rsum+=nums[rindex];
            rindex--;
            maxSum = max(maxSum , lsum + rsum );
        }
        return maxSum;
    }
};