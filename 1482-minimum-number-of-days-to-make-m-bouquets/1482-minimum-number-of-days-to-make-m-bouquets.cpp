class Solution {
public:
    bool canMakeBouquet( const vector<int> &arr , int m , int k , int mid){
        int counter = 0 ;
        for ( int i = 0 ; i < arr.size() ; i++){
            if(arr[i]<=mid){
                counter++;
            }
            else { counter = 0 ;}
            if(counter==k){
                m--;
                counter=0;
                if(m==0) return true;
            }
        }
            return false;  
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long requiredMinFlowers = 1LL * m * k;;
        if(bloomDay.size()<requiredMinFlowers) return -1;
       int s = *min_element(bloomDay.begin(),bloomDay.end());
       int e = *max_element(bloomDay.begin(),bloomDay.end());  
       int ans = 0 ;   
       while(s<=e){
        int mid = s+(e-s)/2;
        if(canMakeBouquet(bloomDay,m , k , mid)){
            ans = mid ;
            e = mid - 1 ;
        }
        else {
            s=mid+1;
            }
       } 
       return ans ;
    }
};