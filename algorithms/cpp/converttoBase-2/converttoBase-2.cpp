// Source: https://leetcode.com/problems/convert-to-base-2/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    string baseNeg2(int N) {
        vector<int> nums = baseK(N, -2);
        string res;
        for (auto x: nums) res += to_string(x);
        return res;
    }
    
private:
    vector<int> baseK(int N, int K) {
        if (N == 0) return {0};
        vector<int> res;
        while (N != 0) {
            int r = ((N % K) + abs(K)) % abs(K);
            res.push_back(r);
            N -= r;
            N /= K;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
