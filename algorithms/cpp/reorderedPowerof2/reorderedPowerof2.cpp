// Source: https://leetcode.com/problems/reordered-power-of-2/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        map<int, int> m = cnt(N);
        for (int i = 0; i < 31; i++) {
            if (m == cnt(1 << i)) return true;
        }
        return false;
    }

private:
    map<int, int> cnt(int n) {
        map<int, int> m;
        while (n) {
            m[n % 10]++;
            n /= 10;
        }
        return m;
    }
};
