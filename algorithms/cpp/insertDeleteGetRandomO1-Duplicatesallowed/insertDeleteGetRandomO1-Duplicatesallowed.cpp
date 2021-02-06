// Source: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Author: Miao Zhang
// Date:   2021-02-05

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        dic[val].push_back(vals.size());
        vals.emplace_back(val, dic[val].size() - 1);
        return dic[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!dic.count(val)) return false;
        int index_in_array = dic[val].back();
        auto& lastval = vals.back();
        
        dic[lastval.first][lastval.second] = index_in_array;
        swap(vals.back(), vals[index_in_array]);
        vals.pop_back();
        dic[val].pop_back();
        if (dic[val].empty()) dic.erase(val);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % vals.size();
        return vals[index].first;
    }

private:
    // val, [index]
    unordered_map<int, vector<int>> dic;
    // val, index
    vector<pair<int, int>> vals;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
