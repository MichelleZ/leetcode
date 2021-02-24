// Source: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> dic;
        for (int i = 0; i < list1.size(); i++) {
            dic[list1[i]] = i;
        }
        vector<string> res;
        int bestsums = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (!dic.count(list2[i])) continue;
            int sums = dic[list2[i]] + i;
            if (sums < bestsums) res.clear();
            if (sums <= bestsums) {
                bestsums = sums;
                res.push_back(list2[i]);
            }
        }
        return res;
    }
};
