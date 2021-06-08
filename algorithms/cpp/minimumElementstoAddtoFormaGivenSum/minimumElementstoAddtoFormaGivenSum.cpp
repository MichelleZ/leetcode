// Source: https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int64_t diff = abs(goal -
                       accumulate(begin(nums), end(nums), 0LL));
        return (diff + limit - 1) / limit;
    }
};
