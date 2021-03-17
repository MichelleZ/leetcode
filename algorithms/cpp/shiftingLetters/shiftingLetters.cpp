// Source: https://leetcode.com/problems/shifting-letters/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            n += (shifts[i] % 26);
            S[i] = (S[i] - 'a' + n) % 26 + 'a';
        }
        return S;
    }
};
