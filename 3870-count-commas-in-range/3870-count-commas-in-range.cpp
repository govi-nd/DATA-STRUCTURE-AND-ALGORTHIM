class Solution {
public:
    int countCommas(int n) {
       int i = 0;
       int count=1000;
       int temp = n;
       while(temp){
        if(i>4) break;
        temp=temp/10;
        i++;
       }
       if(i<4) return 0;
       int diff = n-count;
       return diff+1;
    }
};