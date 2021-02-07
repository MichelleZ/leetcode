// Source: https://leetcode.com/problems/nth-digit/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        int cnt = 9;
        int start = 1;
        long long t = n;
        while (t > (long long)len * cnt) {
            t -= len * cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }
        start += (t - 1) / len;
        char res = to_string(start)[(t - 1) % len];
        return res - '0';
    }
};
