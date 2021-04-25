// Source: https://leetcode.com/problems/reduce-array-size-to-the-half/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto& a: arr) cnt[a]++;
        vector<int> cnts;
        for (auto& [k, v]: cnt) {
            cnts.push_back(v);
        }
        sort(rbegin(cnts), rend(cnts));
        int freq = 0;
        int res = 0;
        for (int c: cnts) {
            freq += c;
            res += 1;
            if (freq * 2 >= arr.size()) {
                break;
            }
        }
        return res;
    }
};
