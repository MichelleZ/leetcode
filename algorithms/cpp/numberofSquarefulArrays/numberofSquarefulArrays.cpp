// Source: https://leetcode.com/problems/number-of-squareful-arrays/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        std::sort(begin(A), end(A));
        vector<int> cur;
        vector<int> used(A.size());
        int res = 0;
        dfs(A, cur, used, res);
        return res;
    }

private:
    bool issquare(int x, int y) {
        int s = sqrt(x + y);
        return s * s == x + y;
    }

    void dfs(const vector<int>& A, vector<int>& cur, vector<int>& used, int& res) {
        if (cur.size() == A.size()) {
            res++;
            return;
        }
        for (int i = 0; i < A.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && !used[i - 1] && A[i] == A[i - 1]) continue;
            if (!cur.empty() && !issquare(cur.back(), A[i])) continue;
            cur.push_back(A[i]);
            used[i] = 1;
            dfs(A, cur, used, res);
            used[i] = 0;
            cur.pop_back();
        }
    }
};
