// Source: https://leetcode.com/problems/count-the-repetitions/
// Author: Miao Zhang
// Date:   2021-02-14

/******************************************************************
 *https://leetcode-cn.com/problems/count-the-repetitions/solution/tong-ji-zhong-fu-ge-shu-by-leetcode-solution/
******************************************************************/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        int s1cnt = 0, index = 0, s2cnt = 0;
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            ++s1cnt;
            for (char ch: s1) {
                if (ch == s2[index]) {
                    index += 1;
                    if (index == s2.size()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }
            if (s1cnt == n1) {
                return s2cnt / n2;
            }
            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                pre_loop = {s1cnt_prime, s2cnt_prime};
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            } else {
                recall[index] = {s1cnt, s2cnt};
            }
        }
        int res = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (char ch: s1) {
                if (ch == s2[index]) {
                    ++index;
                    if (index == s2.size()) {
                        ++res;
                        index = 0;
                    }
                }
            }
        }
        return res / n2;
    }
};
