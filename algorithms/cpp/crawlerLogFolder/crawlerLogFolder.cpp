// Source: https://leetcode.com/problems/crawler-log-folder/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string& log: logs) {
            if (log == "../") {
                res = max(res - 1, 0);
            } else if (log != "./") {
                res++;
            }
        }
        return res;
    }
};
