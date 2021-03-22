// Source: https://leetcode.com/problems/fair-candy-swap/
// Author: Miao Zhang
// Date:   2021-03-22

/**************************************************************
 * sumA - x + y = sumB - y + x
 * x + (sumB - sumA) / 2 = y
**************************************************************/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = accumulate(A.begin(), A.end(), 0);
        int sumb = accumulate(B.begin(), B.end(), 0);
        unordered_set<int> s(begin(B), end(B));
        int diff = (sumb - suma) / 2;
        for (int a: A) {
            if (s.count(a + diff)) return {a, a + diff};
        }
        return {};
    }
};
