// Source: https://leetcode.com/problems/all-oone-data-structure/
// Author: Miao Zhang
// Date:   2021-02-10

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = m_.find(key);
        if (it == m_.end()) {
            if (l_.empty() || l_.front().value != 1) {
                l_.push_front({1, {key}});
            } else {
                l_.front().keys.insert(key);
            }
            m_[key] = l_.begin();
            return;
        }

        auto listit = it->second;
        auto nit = next(listit);
        if (nit == l_.end() || nit->value != listit->value + 1) {
            nit = l_.insert(nit, {listit->value + 1, {}});
        }
        nit->keys.insert(key);
        m_[key] = nit;

        listit->keys.erase(key);
        if (listit->keys.empty()) {
            l_.erase(listit);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = m_.find(key);
        if (it == m_.end()) return;
        auto listit = it->second;
        if (listit->value > 1) {
            auto pit = prev(listit);
            if (listit == l_.begin() || pit->value != listit->value - 1) {
                pit = l_.insert(listit, {listit->value - 1, {}});
            }
            pit->keys.insert(key);
            m_[key] = pit;
        } else {
            m_.erase(key);
        }
        listit->keys.erase(key);
        if (listit->keys.empty()) {
            l_.erase(listit);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return l_.empty() ? "" : *l_.back().keys.cbegin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return l_.empty() ? "" : *l_.front().keys.cbegin();
    }

private:
    struct Node {
        int value;
        unordered_set<string> keys;
    };
    // value, eg. 1, 2...
    list<Node> l_;
    // entrance key
    unordered_map<string, list<Node>::iterator> m_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
