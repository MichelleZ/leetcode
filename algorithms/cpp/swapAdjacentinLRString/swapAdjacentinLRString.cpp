// Source: https://leetcode.com/problems/swap-adjacent-in-lr-string/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        // XL -> LX  L left move
        int i = 0;
        // RX -> XR R right move
        int j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (start[i] != end[j]) return false;
            if ((start[i] == 'R' && i > j) || (start[i] == 'L' && i < j)) {
                return false;
            }
            i++;
            j++;
        }
        while (i < n) {
            if (start[i] != 'X') return false;
            i++;
        }
        while (j < n) {
            if (end[j] != 'X') return false;
            j++;
        }
        return true;
    }
};
