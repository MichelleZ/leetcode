// Source: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    Solution(vector<vector<int>>& rects): rects_(std::move(rects)) {
        int sums = 0;
        for (auto r: rects_) {
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sums += area;
            weights_.push_back(sums);
        }
    }
    
    vector<int> pick() {
        int wei = rand() % weights_.back() + 1;
        int idx = lower_bound(weights_.begin(), weights_.end(), wei) - weights_.begin();
        auto& rect = rects_[idx];
        return {rect[0] + rand() % (rect[2] - rect[0] + 1),
               rect[1] + rand() % (rect[3] - rect[1] + 1)};
    }

private:
    vector<vector<int>> rects_;
    vector<int> weights_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
