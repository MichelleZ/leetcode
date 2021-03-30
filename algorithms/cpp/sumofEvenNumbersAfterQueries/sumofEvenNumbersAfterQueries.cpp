// Source: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sums = 0;
        for (int a: A) {
            if (a % 2 == 0) sums += a;
        }
        vector<int> res;
        for (auto& query: queries) {
            int& x = A[query[1]];
            if (x % 2 == 0)
                sums -= x;
            x += query[0];
            if (x % 2 == 0)
                sums += x;
            res.push_back(sums);
        }
        return res;
    }
};
