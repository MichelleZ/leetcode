// Source: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> vals;
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            for (auto num: nums[i]) {
                vals.push_back({num, i});
            }
        }
        sort(vals.begin(), vals.end());
        unordered_map<int, int> dic;
        int left = 0;
        int cnt = 0;
        int diff = INT_MAX;
        vector<int> res;
        for (int right = 0; right < vals.size(); right++) {
            if (dic[vals[right].second] == 0) cnt++;
            dic[vals[right].second]++;
            while (cnt == k && left <= right) {
                if (diff > vals[right].first - vals[left].first) {
                    diff = vals[right].first - vals[left].first;
                    res = {vals[left].first, vals[right].first};
                }
                if (--dic[vals[left].second] == 0) cnt--;
                left++;
            }
        }
        return res;
    }
};
