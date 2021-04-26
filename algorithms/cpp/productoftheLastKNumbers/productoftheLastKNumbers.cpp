// Source: https://leetcode.com/problems/product-of-the-last-k-numbers/
// Author: Miao Zhang
// Date:   2021-04-26

class ProductOfNumbers {
public:
    ProductOfNumbers(): prefix_(1, 1) {

    }

    void add(int num) {
        if (num == 0) {
            prefix_.clear();
            prefix_.push_back(1);
        } else {
            prefix_.push_back(prefix_.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= prefix_.size()) return 0;
        return prefix_.back() / prefix_[prefix_.size() - k - 1];
    }
private:
    vector<int> prefix_;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
