// Source: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> sums;
        for_each(mat.begin(), mat.end(), [&] (const vector<int>& line) {
            sums.push_back(accumulate(line.begin(), line.end(), 0));
        });
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);
        sort(res.begin(), res.end(), [&] (int i, int j) {
            return sums[i] < sums[j] || (sums[i] == sums[j] && i < j);
        });
        res.resize(k);
        return res;
    }
};
