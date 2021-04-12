// Source: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int d = 0;
        for (auto& c: seq) {
            if (c == '(') {
                d++;
                res.push_back(d % 2);
            }
            if (c == ')') {
                res.push_back(d % 2);
                d--;
            }
        }
        return res;
    }
};
