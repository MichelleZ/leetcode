// Source: https://leetcode.com/problems/building-boxes/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int minimumBoxes(int n) {
        int level = 1;
        int cell = 0;
        while (cell + (1 + level) * level / 2 <= n) {
            cell += (1 + level) * level / 2;
            level += 1;
        }
        level -= 1;
        int area = (1 + level) * level / 2;
        int inc = 0;
        while (cell < n) {
            area += 1;
            cell += inc + 1;
            inc++;
        }
        return area;
    }
};
