// Source: https://leetcode.com/problems/maximum-score-from-removing-substrings/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st, st1;
        int res = 0;
        if (x > y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        // ba
        for (char& c: s) {
            if (c != 'a') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    res += y;
                } else {
                    st.push(c);
                }
            }
        }
        // ab
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            if (c != 'a') st1.push(c);
            else {
                if (!st1.empty() && st1.top() == 'b') {
                    st1.pop();
                    res += x;
                } else {
                    st1.push(c);
                }
            }
        }
        return res;
    }
};
