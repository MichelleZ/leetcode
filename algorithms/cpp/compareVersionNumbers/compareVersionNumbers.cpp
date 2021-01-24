// Source: https://leetcode.com/problems/compare-version-numbers/
// Author: Miao Zhang
// Date:   2021-01-23

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parseVersion(version1);
        vector<int> v2 = parseVersion(version2);
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int n1 = (i < v1.size()) ? v1[i] : 0;
            int n2 = (i < v2.size()) ? v2[i] : 0;
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
        }
        return 0;
    }
    
    vector<int> parseVersion(string version) {
        vector<int> res;
        int n = 0;
        for (auto c: version) {
            if (c == '.') {
                res.push_back(n);
                n = 0;
            } else {
                n = n * 10 + (c - '0');
            }
        }
        res.push_back(n);
        return res;
    }
};
