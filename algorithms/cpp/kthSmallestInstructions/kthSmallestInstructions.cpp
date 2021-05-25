// Source: https://leetcode.com/problems/kth-smallest-instructions/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];
        vector<vector<int>> comb(h + v, vector<int>(h));
        comb[0][0] = 1;
        for (int i = 1; i < h + v; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i && j < h; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
        string res;
        for (int i = 0; i < destination[0] + destination[1]; i++) {
            if (h > 0) {
                int tmp = comb[h + v - 1][h - 1];
                if (k > tmp) {
                    res += 'V';
                    v--;
                    k -= tmp;
                } else {
                    res += 'H';
                    h--;
                }
            } else {
                res += 'V';
                v--;
            }
        }
        return res;
    }
};
