// Source: https://leetcode.com/problems/print-zero-even-odd/
// Author: Miao Zhang
// Date:   2021-04-12

class ZeroEvenOdd {
private:
    int n;
    std::mutex mzero_;
    std::mutex meven_;
    std::mutex modd_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        meven_.lock();
        modd_.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            mzero_.lock();
            printNumber(0);
            if (i % 2 == 0) {
                modd_.unlock();
            } else {
                meven_.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i +=2) {
            meven_.lock();
            printNumber(i);
            mzero_.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i +=2) {
            modd_.lock();
            printNumber(i);
            mzero_.unlock();
        }
    }
};
