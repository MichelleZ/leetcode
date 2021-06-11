// Source: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    bool splitString(string s) {
        const int n = s.length();
        vector<long> nums;
        function<bool(int)> dfs = [&](int p) {
            if (p == n) return nums.size() >= 2;
            long cur = 0;
            for (int i = p; i < n && cur < 1e11; ++i) {
                cur = cur * 10 + (s[i] - '0');
                if (nums.empty() || cur + 1 == nums.back()) {
                    nums.push_back(cur);
                    if (dfs(i + 1)) return true;
                    nums.pop_back();
                }
                if (!nums.empty() && cur >= nums.back()) break;
            }
            return false;
        };
        return dfs(0);
    }
};
