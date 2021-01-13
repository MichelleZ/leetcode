// Source: https://leetcode.com/problems/permutation-sequence/
// Author: Miao Zhang
// Date:   2021-01-13

/***********************************************************
 * eg: n = 3
 * 1 (n - 1)!
 * 2 (n - 1)!
 * 3 (n - 1)!
 * define nums [1, 2, 3, ...n]
 * (k - 1) / (n - 1)! = index of nums
 * (k - 1) % (n - 1)! = next k
***********************************************************/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n, 1);
        for (int i = 2; i < n; i++) {
            fac[i] = fac[i - 1] * i;
        }
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }
        k = k - 1;
        string res;
        
        while (n > 0) {
            int cur = fac[n - 1];
            int idx = k / cur;
            k = k % cur;
            res += nums[idx] + '0';
            nums.erase(nums.begin() + idx);
            n -= 1;
        }
        return res;
    }
};
