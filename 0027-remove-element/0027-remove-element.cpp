// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         if(nums.empty()) return 0;
//         int i = 0 ;
//         int j = nums.size()-1;
//         while(j>=0 && nums[j]==val){
//             nums.pop_back();
//             j--;
//         }
//         if(j==0) {
//             return 0;
//         }
//         while(i<j){
//             if(nums[i]==val){
//                 swap(nums[i],nums[j]);i++;j--;
//             }
//             else{
//                 i++;
//             }
//         }
//         return i+1;
//     }
// };
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
            } 
            else {
                i++;
            }
        }

        return i;
    }
};