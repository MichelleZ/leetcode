// Source: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize);
        for (int g : groups) ++count[g % batchSize];
        map<vector<int>, int> cache;
        function<int(int)> dp = [&](int s) {
            auto it = cache.find(count);
            if (it != cache.end()) return it->second;
            int res = 0;
            for (int i = 1; i < batchSize; ++i) {
                if (!count[i]) continue;
                --count[i];
                res = max(res, (s == 0) + dp((s + i) % batchSize));
                ++count[i];
            }
            return cache[count] = res;
        };
        return count[0] + dp(0);
    }
};
