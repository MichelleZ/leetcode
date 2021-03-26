// Source: https://leetcode.com/problems/stamping-the-sequence/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        vector<int> seen(target.size());
        int total = 0;
        while (total < target.size()) {
            bool found = false;
            for (int i = 0; i <= target.size() - stamp.size(); i++) {
                if (seen[i]) continue;
                int l = unStamp(stamp, target, i);
                if (l == 0) continue;
                seen[i] = 1;
                total += l;
                res.push_back(i);
                found = true;
            }
            if (!found) return {};
        }
        reverse(begin(res), end(res));
        return res;
    }

private:
    int unStamp(const string& stamp, string& target, int start) {
        int l = stamp.size();
        for (int i = 0; i < stamp.size(); i++) {
            if (target[start + i] == '?') {
                --l;
            } else if (target[start + i] != stamp[i]) {
                return 0;
            }
        }
        if (l != 0) {
            std::fill(begin(target) + start, begin(target) + start + stamp.size(), '?');
        }
        return l;
    }
};
