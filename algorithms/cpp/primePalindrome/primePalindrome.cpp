// Source: https://leetcode.com/problems/prime-palindrome/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    int primePalindrome(int N) {
        for (int l = 1; l < 6; l++) {
            for (int num = pow(10, l - 1); num < pow(10, l); num++) {
                string s = to_string(num);
                for (int k = l - 2; k >= 0; k--) {
                    s.push_back(s[k]);
                }
                int x = stoi(s);
                if (x >= N && isPrime(x)) return x;
            }
            for (int num = pow(10, l - 1); num < pow(10, l); num++) {
                string s = to_string(num);
                for (int k = l - 1; k >= 0; k--) {
                    s.push_back(s[k]);
                }
                int x = stoi(s);
                if (x >= N && isPrime(x)) return x;
            }
        }
        return -1;
    }

private:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (n %  i == 0) return false;
        }
        return true;
    }
};
