// Source: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> res = split(preorder);
        int diff = 1;
        for (string s: res) {
            diff--;
            if (diff < 0) return false;
            if (s != "#") diff += 2;
        }
        return diff == 0;
    }
    
    vector<string> split(string s) {
        vector<string> res;
        stringstream ss(s);
        string tok;
        while (getline(ss, tok, ',')) {
            res.push_back(tok);
        }
        return res;
    }
};
