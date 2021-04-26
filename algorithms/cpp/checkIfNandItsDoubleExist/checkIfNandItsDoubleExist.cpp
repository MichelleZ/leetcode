// Source: https://leetcode.com/problems/check-if-n-and-its-double-exist/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int& a: arr) {
            if (m.count(a * 2) || (a % 2 == 0 && m.count(a / 2)))
                return true;
            m[a] = 1;
        }
        return false;
    }
};
