// Source: https://leetcode.com/problems/range-sum-query-mutable/
// Author: Miao Zhang
// Date:   2021-02-01

/**************************************************************
 * binary index tree: prefix sum problem O(logn)
 * reconstruct array
 * e[1] = a[1]
 * e[2] = a[1] + a[2]
 * e[3] = a[3]
 * e[4] = a[1] + a[2] + a[3] + a[4]
 * 1->10->100; 101->110->1000
**************************************************************/
class BinaryIndexTree {
public:
    BinaryIndexTree(int n): sums_(n + 1, 0) {
        
    }
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
};


class NumArray {
public:
    NumArray(vector<int>& nums): nums_(nums), tree_(nums.size()) {
          for (int i = 0; i < nums_.size(); i++) {
              tree_.update(i + 1, nums_[i]);
          }
    }
    
    void update(int index, int val) {
        tree_.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return tree_.query(right + 1) - tree_.query(left);
    }

private:
    vector<int> nums_;
    BinaryIndexTree tree_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
