// Source: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) return false;
        }
        return true;
    }
};
