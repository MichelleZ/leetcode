// Source: https://leetcode.com/problems/circular-permutation-in-binary-representation/
// Author: Miao Zhang
// Date:   2021-04-19

/******************************************************
 * G = B ^ B >> 1
 *  binary code      gray code
 *      0 000             0 000
 *      1 001             1 001
 *      2 010             3 011
 *      3 011             2 010
 *      4 100             6 110
 *      5 101             7 111
 *      6 110             5 101
 *      7 111             4 100
*******************************************************/
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res(1 << n);
        for (int i = 0; i < 1 << n; i++) {
            res[i] = start ^ i ^ i >> 1;
        }
        return res;
    }
};
