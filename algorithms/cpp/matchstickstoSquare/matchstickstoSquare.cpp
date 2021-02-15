// Source: https://leetcode.com/problems/matchsticks-to-square/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() == 0) return false;
        int sum = 0;
        for (int n: nums) sum += n;
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        return dfs(nums, 0, sum / 4, 0, 1, visited);
    }

    bool dfs(vector<int>& nums, int pos, int target, int tmpSum, int groupId, vector<bool>& visited) {
        if (groupId == 4) return true;
        if (tmpSum == target) return dfs(nums, 0, target, 0, groupId + 1, visited);
        if (tmpSum > target) return false;
        for (int i = pos; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            if (dfs(nums, i + 1, target, tmpSum + nums[i], groupId, visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};
