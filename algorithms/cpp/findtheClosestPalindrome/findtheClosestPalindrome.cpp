// Source: https://leetcode.com/problems/find-the-closest-palindrome/
// Author: Miao Zhang
// Date:   2021-02-22

/**********************************************************
 * n = 123
 * [99, 1001]
 * n is palindrome 121, 111 or 131, -1 or +1
 * n is not palindrome 123: 121
**********************************************************/
class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.length();
        long num = stol(n);
        long res = LONG_MAX;
        long mindiff = LONG_MAX;
        unordered_set<long> resset;
        resset.insert(pow(10, len) + 1);
        resset.insert(pow(10, len - 1) - 1);
        long leftpart = stol(n.substr(0, (len + 1) / 2));
        for (long i = -1; i <= 1; i++) {
            string pre = to_string(leftpart + i);
            string str = pre + string(pre.rbegin() + (len & 1), pre.rend());
            resset.insert(stol(str));
        }
        resset.erase(num);
        for (auto s: resset) {
            long diff = abs(s - num);
            if (diff < mindiff) {
                mindiff = diff;
                res = s;
            } else if (diff == mindiff) {
                res = min(res, s);
            }
        }
        return to_string(res);
    }
};
