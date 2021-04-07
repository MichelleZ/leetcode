// Source: https://leetcode.com/problems/distant-barcodes/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        int pos = 0;
        unordered_map<int, int> cnt;
        for (auto& b: barcodes) cnt[b]++;
        vector<pair<int, int>> tmp;
        vector<int> res(n);
        for (auto& c: cnt) {
            tmp.push_back({c.second, c.first});
        }
        sort(rbegin(tmp), rend(tmp));
        for (auto& t: tmp) {
            for (int i = 0; i < t.first; i++, pos += 2) {
                if (pos >= n) pos = 1;
                res[pos] = t.second;
            }
        }
        return res;
    }
};
