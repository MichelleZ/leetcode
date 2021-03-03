// Source: https://leetcode.com/problems/design-hashmap/
// Author: Miao Zhang
// Date:   2021-03-03

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hashTable = vector<pair<int, int>>(key_range, {-1, -1});
    }

    int find(int key) {
        int k = key % key_range;
        while (hashTable[k].first != key && hashTable[k].first != -1) {
            k = (k + 1) % key_range;
        }
        return key;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto k = find(key);
        hashTable[k] = {key, value};
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto k = find(key);
        if (hashTable[k].first == -1) {
            return -1;
        }
        return hashTable[k].second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto k = find(key);
        if (hashTable[k].first != -1) {
            hashTable[k].first = -1;
        }
    }

private:
    const static int key_range = 1000001;
    vector<pair<int, int>> hashTable;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
