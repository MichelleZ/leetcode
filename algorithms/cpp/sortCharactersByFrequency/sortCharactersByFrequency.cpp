// Source: https://leetcode.com/problems/sort-characters-by-frequency/
// Author: Miao Zhang
// Date:   2021-02-13

class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> m;
        for (auto c: s) m[c]++;
        priority_queue<pair<int, char>> heap;
        for (auto c: m) heap.push({c.second, c.first});
        while (!heap.empty()) {
            auto elem = heap.top();
            heap.pop();
            res.append(elem.first, elem.second);
        }
        return res;
    }
};
