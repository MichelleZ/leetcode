// Source: https://leetcode.com/problems/binary-subarrays-with-sum/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> count(A.size() + 1);
        count[0] = 1;
        int res = 0;
        int sums = 0;
        for (int a: A) {
            sums += a;
            if (sums >= S) res += count[sums - S];
            count[sums]++;
        }
        return res;
    }
};
