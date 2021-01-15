// Source: https://leetcode.com/problems/restore-ip-addresses/
// Author: Miao Zhang
// Date:   2021-01-15

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, res, ip, 0);
        return res;
    }
    
    void dfs(string s, vector<string>& res, string ip, int d) {
        if (s.size() > (4 - d) * 3) return;
        if (d == 4 && s.size() == 0) {
            res.push_back(ip);
            return;
        }
        for (int i = 1; i <= min(3, int(s.size())); i++) {
            string ss = s.substr(0, i);
            if (i == 3 && atoi(ss.c_str()) > 255) continue;
            if (ss[0] == '0' && ss.size() >= 2) continue;
            dfs(s.substr(i), res, ip + (d == 0 ? "": ".") + ss, d + 1);
        }
    }
    
};
