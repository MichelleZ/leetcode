// Source: https://leetcode.com/problems/rle-iterator/
// Author: Miao Zhang
// Date:   2021-03-23

class RLEIterator {
public:
    RLEIterator(vector<int>& A) : A_(std::move(A)), i_(0) {
        
    }
    
    int next(int n) {
        while (n && i_ < A_.size()) {
            if (n >= A_[i_]) {
                n -= A_[i_];
                i_ += 2;
                if (n == 0) return A_[i_ - 1];
            } else {
                A_[i_] -= n;
                return A_[i_ + 1];
            }
        }
        return -1;
    }

private:
    int i_;
    vector<int> A_;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
