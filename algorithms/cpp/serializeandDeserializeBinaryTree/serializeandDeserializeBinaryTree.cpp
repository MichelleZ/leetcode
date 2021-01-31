// Source: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: Miao Zhang
// Date:   2021-01-31

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* root, string& res) {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val);
        res += " ";
        dfs(root->left, res);
        dfs(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return dfs(in);
    }
    
    TreeNode* dfs(istringstream& in) {
        string val;
        in >> val;
        if (val == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = dfs(in);
        node->right = dfs(in);
        return node;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
