// Source: https://leetcode.com/problems/xor-queries-of-a-subarray/
// Author: Miao Zhang
// Date:   2021-04-22

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        vector<int> res;
        for (auto& q: queries) {
            res.push_back(xors[q[1] + 1] ^ xors[q[0]]);
        }
        return res;
    }
};
