// Source: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long res = 0, odd = 0, even = 0;
        for (int x: arr) {
            even += 1;
            if (x % 2 == 1) {
                swap(even, odd);
            }
            res += odd;
        }
        return (int)(res % (int)(1e9 + 7));
    }
};
