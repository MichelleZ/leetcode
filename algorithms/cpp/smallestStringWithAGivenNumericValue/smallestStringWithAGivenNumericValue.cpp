// Source: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        while (k) {
            int d = min(k, 25);
            res[--n] += d;
            k -= d;
        }
        return res;
    }
};
