// Source: https://leetcode.com/problems/largest-values-from-labels/
// Author: Miao Zhang
// Date:   2021-04-08

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < values.size(); i++) {
            q.push({values[i], labels[i]});
        }
        unordered_map<int, int> cnt;
        int res = 0;
        while (num_wanted > 0 && !q.empty()) {
            int value = q.top().first;
            int label = q.top().second;
            q.pop();
            if (++cnt[label] <= use_limit) {
                res += value;
                num_wanted--;
            }
        }
        return res;
    }
};
