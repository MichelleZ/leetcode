// Source: https://leetcode.com/problems/push-dominoes/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> l(n, INT_MAX);
        vector<int> r(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L') {
                l[i] = 0;
                for (int j = i - 1; j >= 0 && dominoes[j] == '.'; j--) {
                    l[j] = l[j + 1] + 1;
                }
            } else if (dominoes[i] == 'R') {
                r[i] = 0;
                for (int j = i + 1; j < n && dominoes[j] == '.'; j++) {
                    r[j] = r[j - 1] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (l[i] < r[i]) dominoes[i] = 'L';
            else if (l[i] > r[i]) dominoes[i] = 'R';
        }
        return dominoes;
    }
};
