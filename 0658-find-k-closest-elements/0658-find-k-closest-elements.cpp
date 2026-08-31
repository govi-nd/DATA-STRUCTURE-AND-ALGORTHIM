class Solution {
public:

    int bs(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                return mid;
            }
            else if (arr[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // high = index of element just smaller than x
        // low = index of element just greater than x

        if (x - arr[high] <= arr[low] - x) {
            return high;
        }

        return low;
    }


    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();
        vector<int> ans;

        // x is greater than all elements
        if (x >= arr[n - 1]) {
            for (int i = n - k; i < n; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        // x is smaller than all elements
        if (x <= arr[0]) {
            for (int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        // Find closest element
        int index = bs(arr, x);

        // Start with closest element included
        int left = index - 1;
        int right = index + 1;

        k--; 

        // Expand window until we have k elements
        while (k > 0) {

            if (left < 0) {
                right++;
            }

            else if (right >= n) {
                left--;
            }

            else if (x - arr[left] <= arr[right] - x) {
                left--;
            }

            else {
                right++;
            }

            k--;
        }

        // Our answer window is:
        // left + 1  to  right - 1

        for (int i = left + 1; i <= right - 1; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};