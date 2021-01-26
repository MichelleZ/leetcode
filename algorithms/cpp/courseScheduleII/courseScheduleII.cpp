// Source: https://leetcode.com/problems/course-schedule-ii/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto pre: prerequisites) {
            graph[pre[0]].push_back(pre[1]); 
        }
        vector<int> visited(numCourses, 0);
        vector<int> path;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, visited, i, path)) return {};
        }
        return path;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, 
             int i, vector<int>& path) {
        if (visited[i] == 1) return false;
        if (visited[i] == 2) return true;
        visited[i] = 1;
        for (auto j: graph[i]) {
            if (!dfs(graph, visited, j, path)) return false;
        }
        visited[i] = 2;
        path.push_back(i);
        return true;
    }
};
