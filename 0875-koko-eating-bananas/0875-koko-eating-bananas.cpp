class Solution {
public:
    bool canKokoEatBananas(vector<int> &arr , int k , int h){
        double totalhrs = 0 ;
        for ( int i = 0 ; i < arr.size() ; i ++) {
            totalhrs = totalhrs + ceil(( (double)arr[i] / k ));
        }
        if(totalhrs <= h)
        {
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1 ;
        int e = *max_element(piles.begin(),piles.end());
        int ans = 0 ;
        while (s<=e){
            int mid = s + (e-s)/2 ;
            if (canKokoEatBananas(piles,mid, h)){
                ans = mid ;
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return ans;
    }
};