// Source: https://leetcode.com/problems/print-in-order/
// Author: Miao Zhang
// Date:   2021-04-12

class Foo {
public:
    Foo() {
        first_.lock();
        second_.lock();
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_.unlock();
    }

    void second(function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        first_.lock();
        printSecond();
        first_.unlock();
        second_.unlock();
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        second_.lock();
        printThird();
        second_.unlock();
    }

private:
    std::mutex first_;
    std::mutex second_;
};
