// Source: https://leetcode.com/problems/beautiful-arrangement/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    int countArrangement(int n) {
        int res = 0;
        vector<int> visited(n + 1, 0);
        helper(n, visited, 1, res);
        return res;
    }

    void helper(int n, vector<int>& visited, int pos, int& res) {
        if (pos > n) {
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && (i % pos == 0 || pos % i == 0)) {
                visited[i] = 1;
                helper(n, visited, pos + 1, res);
                visited[i] = 0;
            }
        }
    }
};
