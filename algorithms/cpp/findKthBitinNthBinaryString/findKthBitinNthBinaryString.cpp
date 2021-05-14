// Source: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int l = (1 << n) - 1;
        if (k == (l + 1) / 2) return '1';
        else if (k < (l + 1) / 2) {
            return findKthBit(n - 1, k);
        }
        return invert(findKthBit(n - 1, l + 1 - k));
    }

private:
    char invert(char bit) {
        return (char) ('0' + '1' - bit);
    }
};
