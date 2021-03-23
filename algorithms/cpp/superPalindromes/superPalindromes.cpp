// Source: https://leetcode.com/problems/super-palindromes/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long l = stol(left);
        long r = stol(right);
        long MAGIC = 100000;
        int res = 0;
        for (int i = 1; i < MAGIC; i++) {
            string s = to_string(i);
            for (int j = s.size() - 2; j >= 0; j--) {
                s.push_back(s[j]);
            }
            long v = stoi(s);
            v *= v;
            if (v > r) break;
            if (v >= l && isPalindrome(v)) {
                res++;
            }
        }
        for (int i = 1; i < MAGIC; i++) {
            string s = to_string(i);
            for (int j = s.size() - 1; j >= 0; j--) {
                s.push_back(s[j]);
            }
            long v = stoi(s);
            v *= v;
            if (v > r) break;
            if (v >= l && isPalindrome(v)) {
                res++;
            }
        }
        return res;
    }

private:
    bool isPalindrome(long x) {
        return x == reverse(x);
    }

    long reverse(long x) {
        long res = 0;
        while (x > 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return res;
    }
};
