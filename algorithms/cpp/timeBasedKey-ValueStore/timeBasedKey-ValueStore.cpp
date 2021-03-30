// Source: https://leetcode.com/problems/time-based-key-value-store/
// Author: Miao Zhang
// Date:   2021-03-30

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dic_[key].emplace(timestamp, std::move(value));
    }
    
    string get(string key, int timestamp) {
        auto it = dic_.find(key);
        if (it == dic_.end()) return "";
        auto it1 = it->second.upper_bound(timestamp);
        if (it1 == begin(it->second)) return "";
        return prev(it1)->second;
    }

private:
    unordered_map<string, map<int, string>> dic_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
