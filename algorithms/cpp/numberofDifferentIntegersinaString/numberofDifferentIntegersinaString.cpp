// Source: https://leetcode.com/problems/number-of-different-integers-in-a-string/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int numDifferentIntegers(string word) {
        word += "$";
        unordered_set<string> s;
        deque<char> q;
        for (char c: word) {
            if (isdigit(c)) {
                q.push_back(c);
            } else if (!q.empty()) {
                while (q.size() > 1 && q[0] == '0')
                    q.pop_front();
                s.insert({begin(q), end(q)});
                q.clear();
            }
        }
        return s.size();
    }
};
