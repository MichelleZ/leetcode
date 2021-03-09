// Source: https://leetcode.com/problems/reorganize-string/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        unordered_map<char, int> dic;
        priority_queue<pair<int, char>> q;
        for (char c: S) dic[c]++;
        for (auto ele: dic) {
            if (ele.second > (S.size() + 1) / 2) return "";
            q.push({ele.second, ele.first});
        }
        while (q.size() >= 2) {
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res.push_back(t1.second);
            res.push_back(t2.second);
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size() > 0) res.push_back(q.top().second);
        return res;
    }
};
