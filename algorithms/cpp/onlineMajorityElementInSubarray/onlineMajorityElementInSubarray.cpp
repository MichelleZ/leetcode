// Source: https://leetcode.com/problems/online-majority-element-in-subarray/
// Author: Miao Zhang
// Date:   2021-04-13

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr): nums(arr) {

    }

    int query(int left, int right, int threshold) {
        int key = left * 20000 + right;
        if (!seen.count(key)) {
            int c[20001] = {0};
            int best = (right - left) / 2;
            int bestnum = -1;
            for (int i = left; i <= right; i++) {
                if (++c[nums[i]] > best) {
                    best = c[nums[i]];
                    bestnum = nums[i];
                }
            }
            seen[key] = {bestnum, best};
        }
        return seen[key].second >= threshold ? seen[key].first : -1;
    }

private:
    unordered_map<int, pair<int, int>> seen;
    const vector<int>& nums;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
