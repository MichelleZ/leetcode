// Source: https://leetcode.com/problems/lexicographical-numbers/
// Author: Miao Zhang
// Date:   2021-02-06

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            helper(i, n, res);
        }
        return res;
    }
    
    void helper(int cur, int n, vector<int>& res) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; i++) {
            int newcur = cur * 10 + i;
            if (newcur > n) return;
            helper(newcur, n, res);
        }
    }
};
