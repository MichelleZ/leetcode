// Source: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        std::sort(begin(A), end(A));
        for (int& a: A) {
            if (!K) break;
            if (a < 0) {
                a = -a;
                K--;
            }
        }
        return accumulate(begin(A), end(A), 0) - (K % 2 ? *min_element(begin(A), end(A)) * 2 : 0);
    }
};
