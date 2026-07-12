class Solution {
public:
    // vector<int> twoPtr(vector<int>& arr, int k, int x) {
    //     int l = 0;
    //     int h = arr.size() - 1;
    //     while ((h - l) >= k) {
    //         if (x - arr[l] > arr[h] - x) {
    //             l++;
    //         } else {
    //             h--;
    //         }
    //     }
    //     vector<int> ans;
    //     for (int i = l; i <= h; i++) {
    //         ans.push_back(arr[i]);
    //     }
    //     return ans;
    // }
    int lowerBound(vector<int>& arr, int x) {
    int l = 0, h = arr.size() - 1;
    int ans = arr.size();  // default (if all < x)

    while (l <= h) {
        int mid = (l + h) / 2;
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

    // find first index >= x
    int h = lowerBound(arr,x);
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
        // return twoPtr(arr,k,x);
        return bs_approach(arr,k,x);
    }
};