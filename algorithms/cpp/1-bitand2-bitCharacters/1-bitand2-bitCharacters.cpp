// Source: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author: Miao Zhang
// Date:   2021-03-03

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.empty()) return false;
        if (bits.size() == 1) return bits[0] == 0;
        vector<int> t;
        if (bits[0] == 0) {
            t = vector<int>(bits.begin() + 1, bits.end());
        } else if (bits[0] == 1) {
            t = vector<int>(bits.begin() + 2, bits.end());
        }
        return isOneBitCharacter(t);
    }
};
