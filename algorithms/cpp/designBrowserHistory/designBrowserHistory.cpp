// Source: https://leetcode.com/problems/design-browser-history/
// Author: Miao Zhang
// Date:   2021-05-09

class BrowserHistory {
public:
    BrowserHistory(string homepage): idx_(0) {
        urls_.push_back(std::move(homepage));
    }

    void visit(string url) {
        while (urls_.size() > idx_ + 1) {
            urls_.pop_back();
        }
        idx_++;
        urls_.push_back(std::move(url));
    }

    string back(int steps) {
        idx_ = max(idx_ - steps, 0);
        return urls_[idx_];
    }

    string forward(int steps) {
        idx_ = min(idx_ + steps, int(urls_.size()) - 1);
        return urls_[idx_];
    }

private:
    int idx_;
    vector<string> urls_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
