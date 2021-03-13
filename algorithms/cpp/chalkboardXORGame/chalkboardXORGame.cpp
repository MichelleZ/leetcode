// Source: https://leetcode.com/problems/chalkboard-xor-game/
// Author: Miao Zhang
// Date:   2021-03-13

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) return true;
        int x = 0;
        for (int num: nums) x ^= num;
        return x == 0;
    }
};
