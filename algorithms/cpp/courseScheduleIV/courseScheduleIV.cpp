// Source: https://leetcode.com/problems/course-schedule-iv/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses, vector<int>(numCourses));
        for (const auto& p: prerequisites) {
            g[p[0]][p[1]] = 1;
        }
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    g[i][j] |= g[i][k] & g[k][j];
                }
            }
        }
        vector<bool> res;
        for (auto& q: queries) {
            res.push_back(g[q[0]][q[1]]);
        }
        return res;
    }
};
