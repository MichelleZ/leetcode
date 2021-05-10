// Source: https://leetcode.com/problems/making-file-names-unique/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string, int> m;
        for (string& name: names) {
            string uniquename = name;
            int i = m[name];
            if (i > 0) {
                while (m.count(uniquename = name + "(" + to_string(i++) + ")"));
                m[name] = i;
            }
            m[uniquename] = 1;
            res.push_back(uniquename);
        }
        return res;
    }
};
