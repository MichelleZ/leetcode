// Source: https://leetcode.com/problems/array-of-doubled-pairs/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int a: arr) cnt[a]++;
        sort(begin(arr), end(arr), [] (int a, int b) {
            return abs(a) < abs(b);
        });
        for (int x: arr) {
            if (cnt[x] == 0) continue;
            if (cnt[x * 2] == 0) return false;
            cnt[x] -= 1;
            cnt[x * 2] -= 1;
        }
        return true;
    }
};

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int a : arr) ++cnt[a];
        vector<int> keys;
        for (const auto &kv : cnt) keys.push_back(kv.first);
        sort(begin(keys), end(keys), [](int a, int b) { return abs(a) < abs(b); });
        for (int key : keys)
            if (cnt[key] && (cnt[key * 2] -= cnt[key]) < 0) return false;
        return true;
    }
};
