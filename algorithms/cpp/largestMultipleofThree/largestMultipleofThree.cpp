// Source: https://leetcode.com/problems/largest-multiple-of-three/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10);
        for (int d: digits) cnt[d]++;
        const int r = accumulate(begin(digits), end(digits), 0) % 3;
        vector<vector<int>> remainders{{0, 3, 6, 9}, {1, 4, 7}, {2, 5, 8}};

        auto getNum = [&] (const vector<int>& ds) {
            for (int d: ds)  cnt[d]--;
            string res;
            for (int d = 9; d >= 1; d--) {
                res.append(cnt[d], d + '0');
            }
            res.append(res.empty() ? min(1, cnt[0]) : cnt[0], '0');
            return res;
        };

        if (r == 0) return getNum({});
        for (int d: remainders[r]) {
            if (cnt[d]) return getNum({d});
        }
        for (int d1: remainders[3 - r]) {
            for (int d2: remainders[3 - r]) {
                if ((d1 == d2 && cnt[d1] > 1) || (d1 != d2 && cnt[d1] && cnt[d2])) {
                    return getNum({d1, d2});
                }
            }
        }
        return "";
    }
};
