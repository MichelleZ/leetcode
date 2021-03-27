// Source: https://leetcode.com/problems/valid-mountain-array/
// Author: Miao Zhang
// Date:   2021-03-27

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        bool up = false;
        bool down = false;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                if (down) return false;
                up = true;
            } else if (arr[i] < arr[i - 1]) {
                if (!up) return false;
                down = true;
            } else {
                return false;
            }
        }
        return up && down;
    }
};
