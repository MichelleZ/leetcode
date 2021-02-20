// Source: https://leetcode.com/problems/continuous-subarray-sum/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        dic[0] = -1;
        int sums = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums += nums[i];
            if (k != 0) sums %= k;
            if (dic.count(sums)) {
                if (i - dic.at(sums) > 1) return true;
            } else {
                dic[sums] = i;
            }
        }
        return false;
    }
};
