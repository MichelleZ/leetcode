// Source: https://leetcode.com/problems/validate-binary-tree-nodes/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegrees(n);
        for (auto& l: leftChild) {
            if (l >= 0) indegrees[l]++;
        }
        for (auto& r: rightChild) {
            if (r >= 0) indegrees[r]++;
        }
        int root = -1;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] > 1) return false;
            if (indegrees[i] == 0) {
                root = i;
                zeros++;
            }
        }
        if (zeros != 1) return false;
        vector<int> seen(n);
        queue<int> q;
        q.push(root);
        seen[root] = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (leftChild[cur] != -1 && !seen[leftChild[cur]]) {
                q.push(leftChild[cur]);
                seen[leftChild[cur]] = 1;
            }
            if (rightChild[cur] != -1 && !seen[rightChild[cur]]) {
                q.push(rightChild[cur]);
                seen[rightChild[cur]] = 1;
            }
        }
        return accumulate(begin(seen), end(seen), 0) == n;
    }
};
