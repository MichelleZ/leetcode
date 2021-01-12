// Source: https://leetcode.com/problems/permutations-ii/
// Author: Miao Zhang
// Date:   2021-01-12

/*******************************************************
 * Pruning condition: 
 * Once the previous element has been added(false->true->false), 
 * the later one will not be added.
*******************************************************/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        dfs(nums, path, res, visited);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, path, res, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};
