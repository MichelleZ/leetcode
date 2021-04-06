// Source: https://leetcode.com/problems/escape-a-large-maze/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long> block;
        for(auto& b: blocked) {
            block.insert(b[0] * 1e6 + b[1]);
        }

        unordered_set<long> visited1{};
        unordered_set<long> visited2{};
        return dfs(source, target, source, block, visited1) && dfs(target, source, target, block, visited2);
    }

private:
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<int>& source, vector<int>& target, vector<int> cur, unordered_set<long>& block, unordered_set<long>& visited) {
        if (cur[0] == target[0] && cur[1] == target[1]) return true;
        if (abs(source[0] - cur[0]) + abs(source[1] - cur[1]) > 200) return true;
        visited.insert(cur[0] * 1e6 + cur[1]);
        for (auto& d: dirs) {
            int x = cur[0] + d[0];
            int y = cur[1] + d[1];
            if (x >= 0 && x < 1e6 && y >= 0 && y < 1e6 && !block.count(x * 1e6 + y) && !visited.count(x * 1e6 + y)) {
                if (dfs(source, target, vector<int>{x, y}, block, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
