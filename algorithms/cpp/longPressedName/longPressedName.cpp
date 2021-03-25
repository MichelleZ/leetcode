// Source: https://leetcode.com/problems/long-pressed-name/
// Author: Miao Zhang
// Date:   2021-03-25

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        while (j < typed.size() && typed[j] == typed[j - 1]) j++;
        return i == name.size() && j == typed.size();
    }
};
