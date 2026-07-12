class Solution {
public:
    int lowerBound(vector<int>& arr, int x) {
        int l = 0, h = arr.size() - 1;
        int ans = arr.size();

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<int> bs_approach(vector<int>& arr, int k, int x) {
        int n = arr.size();

        // First index having value >= x
        int h = lowerBound(arr, x);
        int l = h - 1;

        while (k--) {
            if (l < 0) {
                h++;
            } else if (h >= n) {
                l--;
            } else if (x - arr[l] > arr[h] - x) {
                h++;
            } else {
                l--;
            }
        }

        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return bs_approach(arr, k, x);
    }
};