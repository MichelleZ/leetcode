// Source: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) return false;
        map<int, int> m;
        for (auto n: nums) m[n]++;
        while (m.size()) {
            auto it = m.begin();
            const int s = it->first;
            for (int i = 0; i < k; i++, it++) {
                if (it->first != s + i) return false;
                if (--it->second == 0) m.erase(it);
            }
        }
        return true;
    }
};
