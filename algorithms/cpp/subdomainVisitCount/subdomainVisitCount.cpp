// Source: https://leetcode.com/problems/subdomain-visit-count/
// Author: Miao Zhang
// Date:   2021-03-13

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counter;
        for (const string& cpdomain: cpdomains) {
            size_t idx = cpdomain.find(' ');
            int cnt = std::stoi(cpdomain.substr(0, idx));
            string domain = cpdomain.substr(idx + 1);
            while (true) {
                counter[domain] += cnt;
                size_t i = domain.find('.');
                if (i == string::npos) break;
                domain = domain.substr(i + 1);
            }
        }
        vector<string> res;
        for (const auto& kv: counter) {
            res.push_back(std::to_string(kv.second) + " " + kv.first);
        }
        return res;
    }
};
