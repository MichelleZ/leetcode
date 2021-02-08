// Source: https://leetcode.com/problems/frog-jump/
// Author: Miao Zhang
// Date:   2021-02-08

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> dic;
        return dfs(stones, 0, 0, dic);
    }

private:
    bool dfs(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& dic){
        int n = stones.size();
        int key = pos | jump << 11;
        if (pos >= n - 1) return true;
        if (dic.count(key)) return dic[key];
        for (int i = pos + 1; i < n; i++) {
            int dist = stones[i] - stones[pos];
            if (dist < jump - 1) continue;
            if (dist > jump + 1) return dic[key] = false;
            if (dfs(stones, i, dist, dic)) {
                dic[key] = true;
                return dic[key];
            }
        }
        dic[key] = false;
        return dic[key];
    }
};
