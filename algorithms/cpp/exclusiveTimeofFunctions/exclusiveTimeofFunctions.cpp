// Source: https://leetcode.com/problems/exclusive-time-of-functions/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        char action[6];
        int pid;
        int time;
        int prev;
        stack<int> st;
        for (auto& log: logs) {
            sscanf(log.c_str(), "%d:%[a-z]:%d", &pid, action, &time);
            if (action[0] == 's') {
                if (!st.empty()) {
                    res[st.top()] += time - prev;
                }
                st.push(pid);
                prev = time;
            } else {
                res[st.top()] += time - prev + 1;
                st.pop();
                prev = time + 1;
            }
        }
        return res;
    }
};
