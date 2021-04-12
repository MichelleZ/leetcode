// Source: https://leetcode.com/problems/longest-well-performing-interval/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> idx;
        int sums = 0;
        int res = 0;
        for (int i = 0; i < hours.size(); i++) {
            sums += hours[i] > 8 ? 1: -1;
            if (sums > 0) {
                res = i + 1;
            } else {
                if (!idx.count(sums)) {
                    idx[sums] = i;
                }
                if (idx.count(sums - 1)) {
                    res = max(res, i - idx[sums - 1]);
                }
            }
        }
        return res;
    }
};
