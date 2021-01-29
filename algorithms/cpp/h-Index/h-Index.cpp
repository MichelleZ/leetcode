// Source: https://leetcode.com/problems/h-index/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int l = 0;
        int r = n - 1;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            res = max(res, min(citations[mid], n - mid));
            if (citations[mid] < n - mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
