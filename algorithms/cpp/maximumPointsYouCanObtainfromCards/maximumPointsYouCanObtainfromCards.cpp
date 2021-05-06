// Source: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int cur = accumulate(begin(cardPoints), begin(cardPoints) + k, 0);
        int res = cur;
        for (int i = 0; i < k; i++) {
            cur = cur - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            res = max(res, cur);
        }
        return res;
    }
};
