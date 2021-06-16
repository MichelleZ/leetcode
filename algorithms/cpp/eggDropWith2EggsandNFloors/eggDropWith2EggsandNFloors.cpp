// Source: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    int twoEggDrop(int n) {
        return (int)ceil((-1.0 + sqrt(1 + 8 * n)) / 2);
    }
};
