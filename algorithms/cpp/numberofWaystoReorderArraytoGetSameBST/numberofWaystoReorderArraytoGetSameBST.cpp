// Source: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        int kMod = 1e9 + 7;
        vector<vector<int>> cnk(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) cnk[i][j] = 1;
                else cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % kMod;
            }
        }

        function<int(vector<int>)> trees = [&] (const vector<int>& nums) {
            int n = nums.size();
            if (n <= 2) return 1;
            vector<int> left;
            vector<int> right;
            for (int i = 1; i< nums.size(); i++) {
                if (nums[i] < nums[0]) left.push_back(nums[i]);
                else right.push_back(nums[i]);
            }
            long res = cnk[n - 1][left.size()];
            res = (res * trees(left)) % kMod;
            res = (res * trees(right)) % kMod;
            return static_cast<int>(res);
        };

        return trees(nums) - 1;
    }
};
