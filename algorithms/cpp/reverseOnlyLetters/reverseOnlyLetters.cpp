// Source: https://leetcode.com/problems/reverse-only-letters/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.size() - 1;
        while (i < j) {
            if (isalpha(S[i]) && isalpha(S[j])) {
                swap(S[i++], S[j--]);
            } else {
                if (!isalpha(S[i])) i++;
                if (!isalpha(S[j])) j--;
            }
        }
        return S;
    }
};
