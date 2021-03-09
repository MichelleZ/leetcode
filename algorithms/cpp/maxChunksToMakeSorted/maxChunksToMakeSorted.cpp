// Source: https://leetcode.com/problems/max-chunks-to-make-sorted/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int idx = 0;
        for (int i = 0; i < arr.size(); i++) {
            idx = max(idx, arr[i]);
            if (idx == i) res++;
        }
        return res;
    }
};
