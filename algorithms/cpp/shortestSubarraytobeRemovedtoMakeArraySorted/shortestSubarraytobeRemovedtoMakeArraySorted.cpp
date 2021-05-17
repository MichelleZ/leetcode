// Source: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) j--;
        if (j == 0) return 0;
        int res = j;
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i - 1] > arr[i])
                break;
            while (j < n && arr[i] > arr[j])
                j++;
            // from i to j, remove i + 1 -> j - 1
            res = min(res, j - i - 1);
        }
        return res;
    }
};
