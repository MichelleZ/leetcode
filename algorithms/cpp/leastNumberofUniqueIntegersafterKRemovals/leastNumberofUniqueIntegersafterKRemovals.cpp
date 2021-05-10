// Source: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int a: arr)
            cnt[a]++;
        vector<pair<int, int>> freq(begin(cnt), end(cnt));
        sort(freq.begin(), freq.end(), [] (const auto& a, const auto& b) {
            return a.second < b.second;
        });

        int res = freq.size();
        for (auto [_, v]: freq) {
            if (k >= v) {
                res--;
                k -= v;
            } else {
                break;
            }
        }
        return res;
    }
};
