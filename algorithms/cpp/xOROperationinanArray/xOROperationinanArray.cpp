// Source: https://leetcode.com/problems/xor-operation-in-an-array/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    int xorOperation(int n, int start) {
        int s = start >> 1;
        int e = n & start & 1;
        int res = computexor(s - 1) ^ computexor(s + n - 1);
        return res << 1 | e;
    }

private:
    int computexor(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0;
    }
};
