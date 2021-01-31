// Source: https://leetcode.com/problems/find-median-from-data-stream/
// Author: Miao Zhang
// Date:   2021-01-31

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (double)(max_heap.top() + min_heap.top()) / 2;
        } else {
            return min_heap.top() / 1;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
