// Source: https://leetcode.com/problems/decode-xored-array/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        // en[i] = arr[i] ^ arr[i + 1]
        // arr[i + 1] = en[i] ^ arr[i] = arr[i] ^ arr[i + 1] ^ arr[i]
        int n = encoded.size() + 1;
        vector<int> res(n, first);
        for (int i = 0; i < n - 1; i++) {
            res[i + 1] = res[i] ^ encoded[i];
        }
        return res;
    }
};
