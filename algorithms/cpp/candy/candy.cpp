// Source: https://leetcode.com/problems/candy/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) res[i] = max(res[i], res[i + 1] + 1);
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
