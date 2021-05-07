// Source: https://leetcode.com/problems/destination-city/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> in, out;
        for (const auto& path: paths) {
            in[path[1]]++;
            out[path[0]]++;
        }
        for (auto& [city, val]: in) {
            if (val == 1 && out[city] == 0) return city;
        }
        return "";
    }
};
