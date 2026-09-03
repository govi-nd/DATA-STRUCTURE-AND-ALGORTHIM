class Solution {
public:
    bool isPalindromic(string s) {
        string num;

        for (auto i : s) {
            int charToNumber = (int)i;
            num += bitset<8>(charToNumber).to_string();
        }

        // string rev = num;
        // reverse(rev.begin(), rev.end());
        int i = 0 ;
        int j = num.size()-1;
        while(i<j){
            if(num[i]==num[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }

         return true;
    }
};