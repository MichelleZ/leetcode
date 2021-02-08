// Source: https://leetcode.com/problems/binary-watch/
// Author: Miao Zhang
// Date:   2021-02-08

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i <= num; i++) {
            for (int h: nums(i, 12)) {
                for (int m: nums(num - i, 60)) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }

    vector<int> nums(int b, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (__builtin_popcount(i) == b) {
                res.push_back(i);
            }
        }
        return res;
    }
};
