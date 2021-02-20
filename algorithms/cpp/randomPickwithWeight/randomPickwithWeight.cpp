// Source: https://leetcode.com/problems/random-pick-with-weight/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    Solution(vector<int>& w): sums_(std::move(w)) {
        partial_sum(begin(sums_), end(sums_), begin(sums_));
    }

    int pickIndex() {
        int s = rand() % sums_.back();
        return upper_bound(begin(sums_), end(sums_), s) - begin(sums_);
    }

private:
    vector<int> sums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
