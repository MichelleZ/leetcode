// Source: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> tmp(arr.size());
        std::iota(tmp.begin(), tmp.end(), 0);
        std::sort(tmp.begin(), tmp.end(), [&arr](const int i1, const int i2) {
           return arr[i1] == arr[i2] ? i1 < i2 : arr[i1] < arr[i2];
        });
        int res = 0;
        int idx = 0;
        for (int i = 0; i < tmp.size(); i++) {
            idx = max(idx, tmp[i]);
            if (idx == i) res++;
        }
        return res;
    }
};
