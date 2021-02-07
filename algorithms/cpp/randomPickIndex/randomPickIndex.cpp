// Source: https://leetcode.com/problems/random-pick-index/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            dic[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int> res = dic[target];
        return res[rand() % res.size()];
    }
private:
    unordered_map<int, vector<int>> dic;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
