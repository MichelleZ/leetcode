// Source: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int selfloop = 0;
        vector<int> out(n, 0), in(n, 0);
        for (auto& r: requests) {
            if (r[0] != r[1]) {
                out[r[0]]++;
                in[r[1]]++;
            } else {
                selfloop++;
            }
        }
        vector<vector<int>> req;
        for (auto& r: requests) {
            if (r[0] == r[1] || !out[r[0]] || !in[r[0]] || !out[r[0]] || !out[r[1]])
                continue;
            req.push_back(r);
        }

        int r = req.size();
        int res = 0;

        auto check = [&] (int state) {
            vector<int> in(n, 0), out(n, 0);
            int idx = 0;
            int ret = 0;
            while (state) {
                if (state & 1) {
                    out[req[idx][0]]++;
                    in[req[idx][1]]++;
                    ret++;
                }
                state >>= 1;
                idx++;
            }
            if (in != out) return -1;
            return ret;
        };
        for (int i = (1 << r) - 1; i > 0; i--) {
            res = max(res, check(i));
        }
        return res + selfloop;
    }
};
