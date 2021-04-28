// Source: https://leetcode.com/problems/sort-integers-by-the-power-value/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> vals;
        for (int i = lo; i <= hi; i++) {
            int power = 0;
            int x = i;
            while (x != 1) {
                if (x & 1) x = x * 3 + 1;
                else x /= 2;
                power++;
            }
            vals.emplace_back(power, i);
        }
        sort(begin(vals), end(vals));
        return vals[k - 1].second;
    }
};
