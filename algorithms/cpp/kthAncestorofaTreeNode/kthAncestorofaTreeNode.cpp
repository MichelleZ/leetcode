// Source: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
// Author: Miao Zhang
// Date:   2021-05-10

/*******************************************************************
 * dp[i][j]: jth node, 2 ** i parent
 * dp[i][j] = dp[i - 1][dp[i - 1][j]]
*******************************************************************/
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) : maxlvl_(32 - __builtin_clz(n)), dp_(maxlvl_, vector<int>(n)) {
        dp_[0] = parent;
        for (int i = 1; i < maxlvl_; i++) {
            for (int j = 0; j < n; j++) {
                dp_[i][j] = dp_[i - 1][j] == -1 ? -1 : dp_[i - 1][dp_[i - 1][j]];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < maxlvl_ && node != -1; i++) {
            if (k & (1 << i)) {
                node = dp_[i][node];
            }
        }
        return node;
    }

private:
    int maxlvl_;
    vector<vector<int>> dp_;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
