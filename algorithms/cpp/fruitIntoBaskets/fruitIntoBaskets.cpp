// Source: https://leetcode.com/problems/fruit-into-baskets/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int l = 0;
        int res = 0;
        unordered_map<int, int> cnt;
        for (int r = 0; r < tree.size(); r++) {
            cnt[tree[r]] += 1;
            while (cnt.size() > 2) {
                cnt[tree[l]] -= 1;
                if (cnt[tree[l]] == 0) {
                    auto it = cnt.find(tree[l]);
                    cnt.erase(it);
                }
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
