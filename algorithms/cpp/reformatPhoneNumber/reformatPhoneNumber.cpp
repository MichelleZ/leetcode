// Source: https://leetcode.com/problems/reformat-phone-number/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    string reformatNumber(string number) {
        string num;
        for (char& c: number) {
            if (c != ' ' && c != '-') num += c;
        }
        string res;
        res += num[0];
        for (int i = 1; i < num.size(); i++) {
            if (i % 3 == 0) res += '-';
            res += num[i];
        }
        if (res[res.size() - 2] == '-') {
            swap(res[res.size() - 2], res[res.size() - 3]);
        }
        return res;
    }
};
