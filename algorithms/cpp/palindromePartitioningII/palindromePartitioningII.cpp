// Source: https://leetcode.com/problems/palindrome-partitioning-ii/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int start = 0; 
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= s.size(); i++) {
            dp[i] = i - 1;
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                string subs = s.substr(j, i - j);
                 if (isPalindrome(subs)) {
                     dp[i] = min(dp[i], dp[j] + 1);
                 }
                
            }
        }
        return dp[n];
    }
};
