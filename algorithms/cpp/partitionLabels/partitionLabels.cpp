// Source: https://leetcode.com/problems/partition-labels/
// Author: Miao Zhang
// Date:   2021-03-08

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_index(128, 0);
        for (int i = 0; i < S.size(); i++) {
            last_index[S[i]] = i;
        }
        vector<int> res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < S.size(); i++) {
            end = max(end, last_index[S[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
