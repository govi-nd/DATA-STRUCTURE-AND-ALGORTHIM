class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;
        int sign = 1;
        int num = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {

            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && s[i] > '7'))
                return sign == -1 ? INT_MIN : INT_MAX;

            num = num * 10 + (s[i] - '0');
            i++;
        }

        return sign * num;
    }
};