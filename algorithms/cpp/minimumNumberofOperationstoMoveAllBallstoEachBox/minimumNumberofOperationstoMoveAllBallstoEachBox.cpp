// Source: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        // left side contain self
        for (int i = 0, cnt = 0, s = 0; i < n; i++) {
            res[i] += cnt;
            s += boxes[i] - '0';
            cnt += s;
        }
        // right side
        for (int i = n - 1, cnt = 0, s = 0; i >= 0; i--) {
            res[i] += cnt;
            s += boxes[i] - '0';
            cnt += s;
        }
        return res;
    }
};
