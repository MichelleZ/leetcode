// Source: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> bitarr;
        for (string& a: arr) {
            set<char> s(begin(a), end(a));
            if (s.size() != a.size()) continue;
            bitarr.push_back(0);
            for (char c: a) bitarr.back() |= 1 << (c - 'a');
        }

        int res = 0;
        function<void(int, int)> dfs = [&] (int start, int cur) {
            res = max(res, __builtin_popcount(cur));
            for (int i = start; i < bitarr.size(); i++) {
                if ((cur & bitarr[i]) == 0) {
                    dfs(i + 1, cur | bitarr[i]);
                }
            }
        };

        dfs(0, 0);
        return res;
    }
};
