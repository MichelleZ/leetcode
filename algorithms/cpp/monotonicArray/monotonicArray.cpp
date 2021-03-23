// Source: https://leetcode.com/problems/monotonic-array/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true;
        bool dec = true;
        for (int i = 1; i < A.size(); i++) {
            inc &= (A[i] >= A[i - 1]);
            dec &= (A[i] <= A[i - 1]);
        }
        return inc || dec;
    }
};
