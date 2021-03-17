// Source: https://leetcode.com/problems/keys-and-rooms/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, 0, visited);
        return visited.size() == rooms.size();
    }

    void dfs(vector<vector<int>>& rooms, int cur, unordered_set<int>& visited) {
        if (visited.count(cur)) return;
        visited.insert(cur);
        for (int nxt: rooms[cur]) {
            dfs(rooms, nxt, visited);
        }
    }
};
