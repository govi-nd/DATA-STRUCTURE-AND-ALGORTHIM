// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string s = to_string(x);
//         int i = 0 ;
//         int j = s.size()-1;
//         while(i<j){
//             if(s[i]==s[j]){
//                 i++;j--;
//             }
//             else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }

        int original = x;
        long long reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }

        return original == reversed;
    }
};