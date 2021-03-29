// Source: https://leetcode.com/problems/prison-cells-after-n-days/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> seen(1 << 8, -1);
        while (n > 0) {
            int key = getKey(cells);
            if (seen[key] > 0) {
                n %= seen[key] - n;
            }
            seen[key] = n--;
            if (n < 0) break;
            vector<int> c(8);
            for (int i = 1; i < 7; i++) {
                c[i] = cells[i - 1] == cells[i + 1];
            }
            cells.swap(c);
        }
        return cells;
    }

private:
    int getKey(vector<int>& cells) {
        int key = 0;
        for (int i = 0; i < 8; i++) {
            key |= cells[i] << i;
        }
        return key;
    }
};
