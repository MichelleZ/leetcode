// Source: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Author: Miao Zhang
// Date:   2021-03-02

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): k_(k) {
        for (int num: nums) {
            add(num);
        }
    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > k_) {
            heap.pop();
        }
        return heap.top();
    }

private:
    const int k_;
    priority_queue<int, vector<int>, greater<int>> heap; // min_heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
