// Source: https://leetcode.com/problems/lfu-cache/
// Author: Miao Zhang
// Date:   2021-02-13

struct CacheNode {
    int key;
    int value;
    int freq;
    // point to list location
    list<int>::const_iterator it;
};

class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity), min_freq_(0) {

    }

    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.end()) return -1;
        touch(it->second);
        return it->second.value;
    }

    void put(int key, int value) {
        if (capacity_ == 0) return;

        auto it = m_.find(key);
        if (it != m_.end()) {
            it->second.value = value;
            touch(it->second);
            return;
        }

        if (m_.size() == capacity_) {
            int key_del = l_[min_freq_].back();
            l_[min_freq_].pop_back();
            m_.erase(key_del);
        }

        int freq = 1;
        min_freq_ = 1;
        l_[freq].push_front(key);
        m_[key] = {key, value, 1, l_[freq].cbegin()};
    }

private:
    int capacity_;
    int min_freq_;
    // key->CacheNode
    unordered_map<int, CacheNode> m_;
    // freq-> key
    unordered_map<int, list<int>> l_;

    void touch(CacheNode& node) {
        int prev_freq = node.freq;
        int new_freq = ++node.freq;
        l_[prev_freq].erase(node.it);
        if (l_[prev_freq].empty() && prev_freq == min_freq_) {
            l_.erase(prev_freq);
            min_freq_++;
        }
        l_[new_freq].push_front(node.key);
        node.it = l_[new_freq].cbegin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
