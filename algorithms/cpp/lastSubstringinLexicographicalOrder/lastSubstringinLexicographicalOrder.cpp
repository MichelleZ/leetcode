// Source: https://leetcode.com/problems/last-substring-in-lexicographical-order/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    string lastSubstring(string s) {
        int left = 0,right = 1,k = 0;
        while (right + k < s.length()) {
            if (s[left + k] == s[right + k]){
                k++;
            } else if (s[left + k] < s[right + k]){
                left = right;
                right++;
                k = 0;
            } else {
                right = right + k + 1;
                k = 0;
            }
        }
        return s.substr(left);
    }
};
