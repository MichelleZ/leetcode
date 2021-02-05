// Source: https://leetcode.com/problems/insert-delete-getrandom-o1/
// Author: Miao Zhang
// Date:   2021-02-05

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (dic_.count(val)) return false;
        dic_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!dic_.count(val)) return false;
        int index = dic_[val];
        dic_[vals_.back()] = index;
        dic_.erase(val);
        swap(vals_[index], vals_.back());
        vals_.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % vals_.size();
        return vals_[index];
    }

private:
    unordered_map<int, int> dic_;
    vector<int> vals_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
