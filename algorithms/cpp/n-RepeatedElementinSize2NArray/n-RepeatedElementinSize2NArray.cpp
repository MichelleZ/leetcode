// Source: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i = 0;
        int j = 0;
        while (i == j || A[i] != A[j]) {
            i = rand() % A.size();
            j = rand() % A.size();
        }
        return A[i];
    }
};
