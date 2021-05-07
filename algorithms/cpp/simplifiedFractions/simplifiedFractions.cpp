// Source: https://leetcode.com/problems/simplified-fractions/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (gcd(i, j) == 1)
                    res.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        return res;
    }
};
