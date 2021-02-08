// Source: https://leetcode.com/problems/remove-k-digits/
// Author: Miao Zhang
// Date:   2021-02-08

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size();
        int store = n - k;
        for (auto &t: num) {
            while (res.size() && k && res.back() > t) {
                res.pop_back();
                k--;
            }
            res.push_back(t);
        }
        cout << res << endl;
        while (k) {
            res.pop_back();
            k--;
        }
        res.resize(store);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};
