// Source: https://leetcode.com/problems/design-front-middle-back-queue/
// Author: Miao Zhang
// Date:   2021-05-26

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        q_.push_front(val);
        updateMidit(even() ? -1 : 0);
    }

    void pushMiddle(int val) {
        if (q_.empty()) {
            q_.push_back(val);
        } else {
            q_.insert(even() ? next(midit_) : midit_, val);
        }
        updateMidit(even() ? -1 : 1);
    }

    void pushBack(int val) {
        q_.push_back(val);
        updateMidit(even() ? 0 : 1);
    }

    int popFront() {
        if (q_.empty()) return -1;
        int val = q_.front();
        q_.pop_front();
        updateMidit(even() ? 0 : 1);
        return val;
    }

    int popMiddle() {
        if (q_.empty()) return -1;
        int val = *midit_;
        midit_ = q_.erase(midit_);
        updateMidit(even() ? -1 : 0);
        return val;
    }

    int popBack() {
        if (q_.empty()) return -1;
        int val = q_.back();
        q_.pop_back();
        updateMidit(even() ? -1 : 0);
        return val;
    }

private:
    list<int> q_;
    list<int>::iterator midit_;

    bool even() const {
        return q_.size() % 2 == 0;
    }

    void updateMidit(int flag) {
        if (q_.size() <= 1) {
            midit_ = begin(q_);
        } else {
            if (flag > 0) midit_++;
            if (flag < 0) midit_--;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
