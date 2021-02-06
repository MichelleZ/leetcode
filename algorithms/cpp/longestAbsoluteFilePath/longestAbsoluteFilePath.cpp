// Source: https://leetcode.com/problems/longest-absolute-file-path/
// Author: Miao Zhang
// Date:   2021-02-06

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<pair<int, int>> st;
        st.push({-1, 0});
        int res = 0;
        istringstream ss(input);
        string line = "";
        while (getline(ss, line)) {
            int depth = line.find_last_of("\t") + 1;
            line = line.substr(depth);
            while (!st.empty() && depth <= st.top().first) {
                st.pop();
            }
            if (line.find('.') == string::npos) {
                st.push({depth, line.size() + 1 + st.top().second});
            } else {
                res = std::max(res, int(line.size()) + st.top().second);
            }
        }
        return res;
    }
};
