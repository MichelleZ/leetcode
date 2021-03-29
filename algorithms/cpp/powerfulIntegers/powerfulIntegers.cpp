// Source: https://leetcode.com/problems/powerful-integers/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        for (int a = 1; a < bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                res.insert(a + b);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return {begin(res), end(res)};
    }
};
