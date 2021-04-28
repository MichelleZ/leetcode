// Source: https://leetcode.com/problems/cinema-seat-allocation/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        for (auto& seat: reservedSeats) {
            rows[seat[0]] |= 1 << (seat[1] - 1);
        }
        // some rows empty
        int res = (n - rows.size()) * 2;
        for (const auto& [idx, row]: rows) {
            int left = row & 0b0111100000;
            int mid = row & 0b0001111000;
            int right = row & 0b0000011110;
            if (left == 0 && right == 0) res += 2;
            else if (mid == 0 || left == 0 || right == 0) res++;
        }
        return res;
    }
};
