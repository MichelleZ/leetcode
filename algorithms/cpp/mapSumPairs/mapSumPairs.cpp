// Source: https://leetcode.com/problems/map-sum-pairs/
// Author: Miao Zhang
// Date:   2021-02-28

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        int inc = val;
        if (vals_.count(key)) inc -= vals_[key];
        vals_[key] = val;
        for (int i = 1; i <= key.size(); i++) {
            sums_[key.substr(0, i)] += inc;
        }
    }

    int sum(string prefix) {
        return sums_[prefix];
    }

private:
    unordered_map<string, int> vals_;
    unordered_map<string, int> sums_;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
