// Source: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int leftmax = A[0];
        int curmax = A[0];
        int leftlen = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < leftmax) {
                leftmax = curmax;
                leftlen = i + 1;
            } else {
                curmax = max(curmax, A[i]);
            }
        }
        return leftlen;
    }
};
