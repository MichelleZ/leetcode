// Source: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<int> xors(n + 1);
        for (int i = 0; i < n; i++) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (xors[k + 1] == xors[i]) {
                    res += k - i;
                }
            }
        }
        return res;
    }
};
