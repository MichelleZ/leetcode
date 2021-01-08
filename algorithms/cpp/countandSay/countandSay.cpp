// Source: https://leetcode.com/problems/count-and-say/
// Author: Miao Zhang
// Date:   2021-01-08

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        
        string prestr = countAndSay(n - 1);
        int count = 1;
        res.clear();
        int i;
        for (i = 1; i < prestr.size(); i++) {
            if (prestr[i] == prestr[i - 1]) count++;
            else {
                res += to_string(count) + prestr[i - 1];
                count = 1;
            }
        }
        res += to_string(count) + prestr[i - 1];
        return res;
    }
};
