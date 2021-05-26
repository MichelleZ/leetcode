// Source: https://leetcode.com/problems/design-an-ordered-stream/
// Author: Miao Zhang
// Date:   2021-05-26

class OrderedStream {
public:
    OrderedStream(int n): data_(n + 1) {

    }

    vector<string> insert(int idKey, string value) {
        data_[idKey] = value;
        vector<string> res;
        if (ptr_ == idKey) {
            while (ptr_ < data_.size() && !data_[ptr_].empty()) {
                res.push_back(data_[ptr_++]);
            }
        }
        return res;
    }

private:
    int ptr_ = 1;
    vector<string> data_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
