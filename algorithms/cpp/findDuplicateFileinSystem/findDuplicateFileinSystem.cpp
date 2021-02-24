// Source: https://leetcode.com/problems/find-duplicate-file-in-system/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // content --> filepath/filename
        unordered_map<string, vector<string>> filemap;
        for (auto& path: paths) {
            string folder;
            int i = 0;
            while (path[i] != ' ') folder += path[i++];
            while (i < path.length()) {
                string filename;
                string content;
                i++;
                while (path[i] != '(') filename += path[i++];
                i++;
                while (path[i] != ')') content += path[i++];
                i++;
                filemap[content].push_back(folder + "/" + filename);
            }
        }

        vector<vector<string>> res;
        for (auto& f: filemap) {
            if (f.second.size() > 1) {
                res.push_back(std::move(f.second));
            }
        }
        return res;
    }
};
