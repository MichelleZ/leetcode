// Source: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
