class Solution {
public:
void solve( vector<int> &nums , int index , vector<vector<int>> &result){
    if(index==nums.size()) {
        result.push_back(nums);
        return;
    }
    for( int i = index ; i < nums.size() ; i++){
        swap(nums[i],nums[index]);
        solve(nums,index+1,result);
        swap(nums[i],nums[index]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result ;
        int index = 0 ;
        solve(nums,index,result);
        return result;
    }
};