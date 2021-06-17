// Source: https://leetcode.com/problems/minimum-space-wasted-from-packaging/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int kMod = 1e9 + 7;
        int n = packages.size();
        sort(begin(packages), end(packages));
        vector<long long> sums(n + 1);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + packages[i - 1];
        }
        auto get = [&] (int left, int right) {
            return sums[right + 1] - sums[left];
        };
        long long res = LLONG_MAX;
        for (auto& box: boxes) {
            sort(begin(box), end(box));
            if (packages.back() > box.back()) continue;
            auto pt = packages.begin();
            long long total = 0;
            for (int b: box) {
                if (b < *pt) continue;
                auto ptnxt = prev(upper_bound(pt, packages.end(), b));
                total += (long long)(ptnxt - pt + 1) * b - get(pt - packages.begin(), ptnxt - packages.begin());
                pt = next(ptnxt);
                if (pt == packages.end()) break;
            }
            res = min(res, total);
        }
        return (res == LLONG_MAX ? -1 : res % kMod);
    }
};
