// Source: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int sums = 0;
        for (int i = 0; i < arr.size(); i++) {
            sums += arr[i];
            if (i >= k - 1) {
                if (sums >= threshold * k) res++;
                sums -= arr[i - k + 1];
            }
        }
        return res;
    }
};
