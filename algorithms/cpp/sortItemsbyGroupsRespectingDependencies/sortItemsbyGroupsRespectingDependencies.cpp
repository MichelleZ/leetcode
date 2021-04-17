// Source: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 1. data preprocessing
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) {
                group[i] = m;
                m++;
            }
        }
        // 2. adjacency table for item and group
        vector<vector<int>> itemAdj(n);
        vector<vector<int>> groupAdj(m);
        // 3. indegree array and graph
        vector<int> itemIndegree(n);
        vector<int> groupIndegree(m);

        for (int i = 0; i < group.size(); i++) {
            int curGroup = group[i];
            for (int beforeItem: beforeItems[i]) {
                int beforeGroup = group[beforeItem];
                if (curGroup != beforeGroup) {
                    groupAdj[beforeGroup].push_back(curGroup);
                    groupIndegree[curGroup]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int beforeItem: beforeItems[i]) {
                itemAdj[beforeItem].push_back(i);
                itemIndegree[i]++;
            }
        }
        // 4. get topology res
        vector<int> groupres = topologicalSort(groupAdj, groupIndegree);
        vector<int> itemres = topologicalSort(itemAdj, itemIndegree);
        // 5. get map, key: group -> val: items
        unordered_map<int, vector<int>> group2items;
        for (int& item: itemres) {
            group2items[group[item]].push_back(item);
        }
        // 6. transfer the last res according to groupres
        vector<int> res;
        for (int& group: groupres) {
            if (group2items.count(group)) {
                for (auto& item: group2items[group]) {
                    res.push_back(item);
                }
            }
        }
        return res;
    }

private:
    vector<int> topologicalSort(vector<vector<int>>& adj, vector<int>& indegree) {
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            res.push_back(cur);
            for (int nxt: adj[cur]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        if (res.size() == indegree.size()) {
            return res;
        }
        return vector<int>{};
    }
};
