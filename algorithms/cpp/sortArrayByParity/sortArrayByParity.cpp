// Source: https://leetcode.com/problems/sort-array-by-parity/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) {
                swap(A[i], A[j]);
            }
            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
        }
        return A;
    }
};
