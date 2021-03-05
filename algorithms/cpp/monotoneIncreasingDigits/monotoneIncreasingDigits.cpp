// Source: https://leetcode.com/problems/monotone-increasing-digits/
// Author: Miao Zhang
// Date:   2021-03-05

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string nstr = to_string(N);
        int n = nstr.size();
        int j = n;
        for (int i = n - 1; i > 0; i--) {
            if (nstr[i] >= nstr[i - 1]) continue;
            --nstr[i - 1];
            j = i;
        }
        for (int i = j; i < n; i++) {
            nstr[i] = '9';
        }
        return stoi(nstr);
    }
};
