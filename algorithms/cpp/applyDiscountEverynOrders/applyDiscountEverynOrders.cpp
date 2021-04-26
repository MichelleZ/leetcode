// Source: https://leetcode.com/problems/apply-discount-every-n-orders/
// Author: Miao Zhang
// Date:   2021-04-26

class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n_(n), discount_(discount), customerid_(0) {
        for (int i = 0; i < products.size(); i++) {
            prices_[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        customerid_++;
        double res;
        for (int i = 0; i < product.size(); i++) {
            res += prices_[product[i]] * amount[i];
        }
        if (customerid_ % n_ == 0) {
            res -= res * discount_ / 100;
        }
        return res;
    }

private:
    unordered_map<int, int> prices_;
    int n_;
    int discount_;
    int customerid_;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
