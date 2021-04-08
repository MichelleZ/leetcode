// Source: https://leetcode.com/problems/statistics-from-a-large-sample/
// Author: Miao Zhang
// Date:   2021-04-08

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minval = 255;
        int maxval = 0;
        double mode = -1;
        int modecnt = 0;
        int cnt = 0;
        long sums = 0;
        map<int, int> m;
        for (int i = 0; i <= 255; i++) {
            if (!count[i]) continue;
            minval = min(minval, i);
            maxval = max(maxval, i);
            sums += static_cast<long>(i) * count[i];
            if (count[i] > modecnt) {
                mode = i;
                modecnt = count[i];
            }
            m[cnt += count[i]] = i;
        }
        for (auto& x: m) cout << x.first << " " << x.second << ",";
        auto it1 = m.lower_bound((cnt+1) / 2);
        double median = it1->second;
        auto it2 = next(it1);
        if (cnt % 2 == 0 && it2 != m.end() && it1->first == cnt / 2) {
            median = (median + it2->second) / 2;
        }
        return {static_cast<double>(minval), static_cast<double>(maxval), static_cast<double>(sums) / cnt, median, mode};
    }
};
