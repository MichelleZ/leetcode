// Source: https://leetcode.com/problems/contiguous-array/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sums = 0;
        unordered_map<int, int> dic;
        dic[0] = -1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) sums--;
            else sums++;
            if (dic.count(sums)) res = max(res, i - dic[sums]);
            else dic[sums] = i;
        }
        return res;
    }
};
