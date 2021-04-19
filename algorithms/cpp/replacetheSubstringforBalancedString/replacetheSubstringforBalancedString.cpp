// Source: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        if (n <= 0 || n % 4 != 0) {
            return 0;
        }
        int m = n / 4;
        unordered_map<char, int> cnt;
        for (char c: s) cnt[c]++;
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
            return 0;
        int res = n;
        int left = 0;
        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;
            while (left <= right && cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m ) {
                res = min(res, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }
        return res;
    }
};
