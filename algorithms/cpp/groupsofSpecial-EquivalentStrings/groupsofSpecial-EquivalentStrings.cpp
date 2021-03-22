// Source: https://leetcode.com/problems/groups-of-special-equivalent-strings/
// Author: Miao Zhang
// Date:   2021-03-22

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (const string& a: A) {
            string odd;
            string even;
            for (int i = 0; i < a.size(); i++) {
                if (i % 2) {
                    odd += a[i];
                } else {
                    even += a[i];
                }
            }
            sort(begin(odd), end(odd));
            sort(begin(even), end(even));
            s.insert(odd + even);
        }
        return s.size();
    }
};
