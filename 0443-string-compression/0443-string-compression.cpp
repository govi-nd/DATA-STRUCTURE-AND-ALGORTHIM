class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n) {

            int j = i;

            // Count same consecutive characters
            while (j < n && chars[j] == chars[i]) {
                j++;
            }

            int count = j - i;

            // Write character
            chars[write] = chars[i];
            write++;

            // Write count if greater than 1
            if (count > 1) {

                string s = to_string(count);

                for (char ch : s) {
                    chars[write] = ch;
                    write++;
                }
            }

            i = j;
        }

        return write;
    }
};