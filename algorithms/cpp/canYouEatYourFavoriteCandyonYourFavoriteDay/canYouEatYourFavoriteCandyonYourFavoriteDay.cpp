// Source: https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> sums(n);
        sums[0] = candiesCount[0];
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + candiesCount[i];
        }
        vector<bool> res;
        // [fday+1, (fday + 1) * dcap]
        // [sum[ftype - 1] + 1, sum[ftype]]
        for (auto& q: queries) {
            long long x1 = q[1] + 1;
            long long y1 = static_cast<long long>(q[1] + 1) * q[2];
            long long x2 = (q[0] == 0 ? 1 : sums[q[0] - 1] + 1);
            long long y2 =  sums[q[0]];
            res.push_back(!(x1 > y2 || y1 < x2));
        }
        return res;
    }
};
