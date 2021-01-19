// Source: https://leetcode.com/problems/pascals-triangle-ii/
// Author: Miao Zhang
// Date:   2021-01-19

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++ i) {
            for (int j = rowIndex; j >= 1; j--) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i <= rowIndex; i++) {
            int n = res.size();
            for (int j = n - 1; j >= 1; j--) {
                res[j] += res[j - 1];
            }
            res.push_back(1);
        }
        return res;
    }
};
