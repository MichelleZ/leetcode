// Source: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarrays(A, K) - subarrays(A, K - 1);
    }

private:
    int subarrays(vector<int>& A, int K) {
        vector<int> count(A.size() + 1);
        int res = 0;
        int i = 0;
        for (int j = 0; j < A.size(); j++) {
            if (count[A[j]]++ == 0)
                K--;
            while (K < 0) {
                if (--count[A[i++]] == 0) K++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
