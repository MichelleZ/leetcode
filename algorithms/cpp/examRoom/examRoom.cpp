// Source: https://leetcode.com/problems/exam-room/
// Author: Miao Zhang
// Date:   2021-03-18

class ExamRoom {
public:
    ExamRoom(int N) : N_(N) {
        
    }
    
    int seat() {
        int res;
        if (s_.empty()) res = 0;
        else {
            int dist = *s_.begin();
            res = 0;
            auto left = s_.begin();
            auto right = left;
            while (left != s_.end()) {
                ++right;
                int l = *left;
                int r = right != s_.end() ? *right : (2 * (N_ - 1) - *left);
                int d = (r - l) / 2;
                if (d > dist) {
                    dist = d;
                    res = l + d;
                }
                left = right;
            }
        } 
        s_.insert(res);
        return res;
    }
    
    void leave(int p) {
        s_.erase(p);
    }

private:
    const int N_;
    set<int> s_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
