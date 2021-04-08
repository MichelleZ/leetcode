// Source: https://leetcode.com/problems/brace-expansion-ii/
// Author: Miao Zhang
// Date:   2021-04-08

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> res;
        unordered_set<string> visited;
        stack<string> st;
        st.push(expression);
        while (!st.empty()) {
            string str = st.top(); st.pop();
            if (str.find("{") == string::npos) {
                if (!visited.count(str)) {
                    visited.insert(str);
                    res.push_back(str);
                }
                continue;
            }
            int i = 0, left = 0, right = 0;
            while (str[i] != '}') {
                if (str[i] == '{') left = i;
                i++;
            }
            right = i;
            string before = str.substr(0, left);
            string after = str.substr(right + 1);
            string mid = str.substr(left + 1, right - left - 1);
            istringstream is(mid);
            string t;
            while (getline(is, t, ',')) {
                st.push(before + t + after);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
