// Source: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int w = strs[0].size();
        int res = 0;

        vector<string> cur(n);
        for (int j = 0; j < w; j++) {
            vector<string> cur2(cur);
            for (int i = 0; i < n; i++) {
                cur2[i] += strs[i][j];
            }
            if (isSorted(cur2)) {
                cur = cur2;
            } else {
                res++;
            }
        }
        return res;
    }

private:

    bool isSorted(vector<string> arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
};
