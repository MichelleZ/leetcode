// Source: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push({'*', 0});
        for (char c: s) {
            if (c != st.top().first) {
                st.push({c, 1});
            } else if (++st.top().second == k) {
                st.pop();
            }
        }
        string res;
        while (!st.empty()) {
            res.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
