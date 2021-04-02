// Source: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sums = accumulate(arr.begin(), arr.end(), 0);
        if (sums % 3 != 0) return false;
        int target = sums / 3;
        int i = 0;
        int cur = 0;
        while (i < arr.size()) {
            cur += arr[i];
            if (cur == target) break;
            i++;
        }
        if (cur != target) return false;
        int j = i + 1;
        while (j + 1 < arr.size()) {
            cur += arr[j];
            if (cur == target * 2) 
                return true;
            j++;
        }
        return false;
    }
};
