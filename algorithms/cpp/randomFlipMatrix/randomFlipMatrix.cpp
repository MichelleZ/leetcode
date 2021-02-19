// Source: https://leetcode.com/problems/random-flip-matrix/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    Solution(int n_rows, int n_cols): rows_(n_rows),
        cols_(n_cols), n_(n_rows * n_cols) {

    }

    vector<int> flip() {
        int s = rand() % (n_--);
        int index = s;
        if (dic_.count(s)) {
            index = dic_[s];
        }
        dic_[s] = dic_.count(n_) ? dic_[n_] : n_;
        return {index / cols_, index % cols_};
    }

    void reset() {
        dic_.clear();
        n_ = rows_ * cols_;
    }

private:
    int rows_;
    int cols_;
    int n_;
    unordered_map<int, int> dic_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
