// Source: https://leetcode.com/problems/closest-subsequence-sum/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int res = abs(goal);
        vector<int> t1{0}, t2{0};
        t1.reserve(1 << (n / 2 + 1));
        t2.reserve(1 << (n / 2 + 1));
        for (int i = 0; i < n / 2; i++) {
            for (int j = t1.size() - 1; j >= 0; j--) {
                t1.push_back(t1[j] + nums[i]);
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = t2.size() - 1; j >= 0; j--) {
                t2.push_back(t2[j] + nums[i]);
            }
        }
        set<int> s2(begin(t2), end(t2));
        for (int x: unordered_set<int>(begin(t1), end(t1))) {
            auto it = s2.lower_bound(goal - x);
            if (it != s2.end()) {
                res = min(res, abs(goal - x - *it));
            }
            if (it != s2.begin()) {
                res = min(res, abs(goal - x - *prev(it)));
            }
        }
        return res;
    }
};
