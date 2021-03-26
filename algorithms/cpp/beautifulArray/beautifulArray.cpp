// Source: https://leetcode.com/problems/beautiful-array/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res{1};
        while (res.size() < N) {
            vector<int> t;
            for (int num: res) {
                if (num * 2 - 1 <= N) t.push_back(num * 2 - 1);
            }
            for (int num: res) {
                if (num * 2 <= N) t.push_back(num * 2);
            }
            res = t;
        }
        return res;
    }
};
