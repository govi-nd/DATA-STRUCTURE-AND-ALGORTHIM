class Solution {
public:
    string reverseWords(string s) {
         int n = s.length();

        // Reverse the entire string
        reverse(s.begin(), s.end());

        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++) {

            // Skip extra spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            start = end;

            // Copy one word
            while (i < n && s[i] != ' ') {
                s[end] = s[i];
                end++;
                i++;
            }

            // Reverse the copied word
            reverse(s.begin() + start, s.begin() + end);

            // Add one space after the word
            s[end] = ' ';
            end++;
        }

        // Remove the last extra space
        if (end > 0)
            end--;

        s.resize(end);

        return s;
        }
        // int n = s.length();

        // // Reverse the entire string
        // int i = 0;
        // int j = n - 1;

        // while (i < j) {
        //     swap(s[i], s[j]);
        //     i++;
        //     j--;
        // }

        // // Reverse each word
        // int x = 0;
        // while (x < n) {

        //     // Skip spaces
        //     while (x < n && s[x] == ' ')
        //         x++;

        //     if (x >= n)
        //         break;

        //     int z = x;

        //     // Find end of current word
        //     while (z < n && s[z] != ' ')
        //         z++;

        //     // Reverse the word
        //     reverse(s.begin() + x, s.begin() + z);

        //     x = z;
        // }

        // int write = 0;
        // int read = 0;

        // while (read < n) {

        //     // Skip all spaces
        //     while (read < n && s[read] == ' ')
        //         read++;

        //     if (read >= n)
        //         break;

        //     // Put one space before every word except the first
        //     if (write != 0)
        //         s[write++] = ' ';

        //     // Copy the current word
        //     while (read < n && s[read] != ' ')
        //         s[write++] = s[read++];
        // }

        // s.resize(write);
        // return s;
        // // int n = s.length();
        // // vector<string> str;

        // // for (int i = 0; i < n; i++) {
        // //     if (s[i] == ' ')
        // //         continue;
        // //     else {
        // //         int j = i;

        // //         while (j < n && s[j] != ' ') {
        // //             j++;
        // //         }

        // //         str.push_back(s.substr(i, j - i));
        // //         i = j - 1;   // because the for loop will increment i
        // //     }
        // // }

        // // string ans;

        // // for (int i = str.size() - 1; i >= 0; i--) {
        // //     ans += str[i];

        // //     if (i != 0)
        // //         ans += ' ';
        // // }

        // // return ans;
    
};