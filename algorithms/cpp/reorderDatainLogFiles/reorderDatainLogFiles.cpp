// Source: https://leetcode.com/problems/reorder-data-in-log-files/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto alpha_end = std::stable_partition(begin(logs),  end(logs),
        [](const string& log){ return isalpha(log.back()); });
        std::sort(begin(logs), alpha_end, [](const string& a, const string& b){
            string acon = a.substr(a.find(' '));
            string bcon = b.substr(b.find(' '));
            if (acon == bcon) {
                return a.substr(0, a.find(' ')) < b.substr(0, b.find(' '));
            } else {
                return acon < bcon;
            }
      });
      return logs;
    }
};
