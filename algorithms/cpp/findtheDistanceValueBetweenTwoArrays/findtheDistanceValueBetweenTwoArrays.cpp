// Source: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (int a1: arr1) {
            bool flag = true;
            for (int a2: arr2) {
                if (abs(a1 - a2) <= d) {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
