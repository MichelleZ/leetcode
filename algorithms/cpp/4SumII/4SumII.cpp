// Source: https://leetcode.com/problems/4sum-ii/
// Author: Miao Zhang
// Date:   2021-02-13

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> counter;
        for (int a: A) {
            for (int b: B) {
                counter[a + b]++;
            }
        }
        int res = 0;
        for (int c: C) {
            for (int d: D) {
                auto it = counter.find(-c-d);
                if (it != counter.end()) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};
