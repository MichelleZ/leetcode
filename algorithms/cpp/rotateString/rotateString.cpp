// Source: https://leetcode.com/problems/rotate-string/
// Author: Miao Zhang
// Date:   2021-03-11

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A.length() == 0 && B.length() == 0) return true;
        for (int i = 0; i < A.length(); i++) {
            if (check(A, B, i)) return true;
        }
        return false;
    }

private:
    bool check(const string& A, const string& B, int offset) {
        for (int i = 0; i < A.length(); i++) {
            if (A[(i + offset) % A.length()] != B[i]) return false;
        }
        return true;
    }
};
