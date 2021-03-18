// Source: https://leetcode.com/problems/mirror-reflection/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int n = p;
        int a = q;
        while (n % 2 == 0 && a % 2 == 0) {
            n = n / 2;
            a = a / 2;
        }
        if (n % 2 == 0 && a % 2 == 1) return 2;
        else if (n % 2 == 1 && a % 2 == 1) return 1;
        else if (n % 2 == 1 && a % 2 == 0) return 0;
        return -1;
    }
};
