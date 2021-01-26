// Source: https://leetcode.com/problems/course-schedule/
// Author: Miao Zhang
// Date:   2021-01-25

// dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto pre: prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, visited, i)) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i) {
        if (visited[i] == 1) return false;
        if (visited[i] == 2) return true;
        visited[i] = 1;
        for (auto j: graph[i]) {
            if (!dfs(graph, visited, j)) return false;
        }
        visited[i] = 2;
        return true;
    }
};

// bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        unordered_map<int, int> indegrees;
        for (auto pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            if (indegrees.find(pre[0]) == indegrees.end()) {
                indegrees[pre[0]] = 1;
            } else {
                indegrees[pre[0]] += 1;
            }
        }
        vector<int> path;
        for (int i = 0; i < numCourses; i++) {
            bool zeroDegree = false;
            int j;
            for (j = 0; j < numCourses; j++) {
                if (indegrees[j] == 0) {
                    zeroDegree = true;
                    break;
                }
            }
            if (!zeroDegree) return {};
            if (indegrees.find(j) == indegrees.end()) {
                indegrees[j] = -1;
            } else {
                indegrees[j] -= 1;
            }
            for (auto node: graph[j]) {
                indegrees[node] -= 1;
            }
            path.push_back(j);
        }
        return path;
    }
};
