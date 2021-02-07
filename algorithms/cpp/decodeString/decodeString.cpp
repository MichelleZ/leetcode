// Source: https://leetcode.com/problems/decode-string/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    string decodeString(string s) {
        stack<int> st_num;
        stack<string> st_str;
        string res = "";
        int num = 0;
        for (auto &c: s) {
            if (isdigit(c)) {
                num = 10 * num + c - '0';
            } else if (c == '[') {
                st_str.push(res);
                st_num.push(num);
                res = "";
                num = 0;
            } else if (isalpha(c)) {
                res += c;
            } else if (c == ']') {
                int pre_num = st_num.top();
                st_num.pop();
                string pre_string = st_str.top();
                st_str.pop();
                string ress = "";
                while (pre_num > 0) {
                    ress += res;
                    pre_num--;
                }
                res = pre_string + ress;
            }
        }
        return res;
    }
};
