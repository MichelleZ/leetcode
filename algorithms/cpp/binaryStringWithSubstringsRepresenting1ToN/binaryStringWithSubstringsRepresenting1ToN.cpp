// Source: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = N; i > 0; i--) {
            string b = bitset<32>(i).to_string();
            if (S.find(b.substr(b.find("1"))) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
