// Source: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Author: Miao Zhang
// Date:   2021-03-19

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(nullptr, root);
        vector<int> res;
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> q;
        q.push(target);
        seen.insert(target);
        int k = 0;
        while (!q.empty() && k <= K) {
            int len = q.size();
            while (len--) {
                TreeNode* node = q.front();
                q.pop();
                if (k == K) res.push_back(node->val);
                for (TreeNode* child: graph[node]) {
                    if (seen.count(child)) continue;
                    seen.insert(child);
                    q.push(child);
                }
            }
            k++;
        }
        return res;
    }

private:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    
    void buildGraph(TreeNode* parent, TreeNode* child) {
        if (parent) {
            graph[parent].push_back(child);
            graph[child].push_back(parent);
        }
        if (child->left) buildGraph(child, child->left);
        if (child->right) buildGraph(child, child->right);
    }
};
