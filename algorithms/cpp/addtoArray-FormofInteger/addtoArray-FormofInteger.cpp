// Source: https://leetcode.com/problems/add-to-array-form-of-integer/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        res.reserve(A.size() + 1);
        for (int i = A.size() - 1; i >= 0 || K > 0; i--) {
            K += (i >= 0 ? A[i] : 0);
            res.push_back(K % 10);
            K /= 10;
        }
        reverse(begin(res), end(res));
        return res;
    }
};
