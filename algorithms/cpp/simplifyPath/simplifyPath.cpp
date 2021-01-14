// Source: https://leetcode.com/problems/simplify-path/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') i++;
            string s = "";
            while (i < path.size() && path[i] != '/') {
                s += path[i];
                i++;
            }
            if (".." == s && !st.empty()) st.pop();
            else if (s != "" && s != "." && s != "..") st.push(s);
        }
        if (st.empty()) return "/";
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};
