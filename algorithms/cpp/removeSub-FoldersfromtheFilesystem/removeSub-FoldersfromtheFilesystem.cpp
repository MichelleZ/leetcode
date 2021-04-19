// Source: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Author: Miao Zhang
// Date:   2021-04-18

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s(begin(folder), end(folder));
        vector<string> res;
        for (auto& f: folder) {
            string cur = f;
            bool valid = true;
            while (!cur.empty() && valid) {
                while (cur.back() != '/') cur.pop_back();
                cur.pop_back();
                if (s.count(cur))
                    valid = false;
            }
            if (valid) res.push_back(f);
        }
        return res;
    }
};
