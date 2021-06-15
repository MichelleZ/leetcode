// Source: https://leetcode.com/problems/rotating-the-box/
// Author: Miao Zhang
// Date:   2021-06-15

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for (int i = 0; i < m; i++) {
            deque<int> q;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    q.clear();
                } else if (box[i][j] == '#') {
                    if (!q.empty()) {
                        int pos = q.front();
                        q.pop_front();
                        box[i][pos] = '#';
                        box[i][j] = '.';
                        q.push_back(j);
                    }
                } else {
                    q.push_back(j);
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = box[i][j];
            }
        }
        return res;
    }
};
