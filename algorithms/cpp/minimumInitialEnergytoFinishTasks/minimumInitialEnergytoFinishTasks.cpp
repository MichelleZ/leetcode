// Source: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(begin(tasks), end(tasks), [] (vector<int>& a, vector<int>& b) {
           return a[1] - a[0] > b[1] - b[0]; 
        });
        int res = 0;
        int actual = 0;
        for (auto& t: tasks) {
            res = max(res, actual + t[1]);
            actual += t[0];
        }
        return res;
    }
};
