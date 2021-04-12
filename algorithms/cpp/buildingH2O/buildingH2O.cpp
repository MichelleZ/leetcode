// Source: https://leetcode.com/problems/building-h2o/
// Author: Miao Zhang
// Date:   2021-04-12

class Semaphore {
public:
    Semaphore(int s): s_(s) {}

    void P(int d = 1) {
        unique_lock<mutex> lock(m_);
        while (s_ < d) {
            cv_.wait(lock);
        }
        s_ -= d;
    }

    void V(int d = 1) {
        unique_lock<mutex> lock(m_);
        s_ += d;
        cv_.notify_all();
    }

private:
    std::mutex m_;
    condition_variable cv_;
    int s_;
};


class H2O {
public:
    H2O(): s_h_(2), s_o_(2) {

    }

    void hydrogen(function<void()> releaseHydrogen) {
        s_h_.P();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        s_o_.V();
    }

    void oxygen(function<void()> releaseOxygen) {
        s_o_.P(2);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        s_h_.V(2);
    }

private:
    Semaphore s_h_;
    Semaphore s_o_;
};
