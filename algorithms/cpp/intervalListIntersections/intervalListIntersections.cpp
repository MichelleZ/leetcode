// Source: https://leetcode.com/problems/interval-list-intersections/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size()) {
            int s = max(firstList[i][0], secondList[j][0]);
            int e = min(firstList[i][1], secondList[j][1]);
            if (s <= e) res.push_back({s, e});
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
