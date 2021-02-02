// Source: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author: Miao Zhang
// Date:   2021-02-01

/********************************************************
 * original:[5, 2, 6, 1]
 * reverse: [1, 6, 2, 5]
 * sorted:  [1, 2, 5, 6]
 * ranked:  [1, 4, 2, 3]
 * res:     [0, 1, 1, 2]
********************************************************/
class BinaryIndexTree {
public: 
    BinaryIndexTree(int n): sums_(n + 1, 0) {
        
    }

    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_; 
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank = 0;
        for (const int num: sorted) {
            ranks[num] = ++rank;
        }
        
        vector<int> res;
        BinaryIndexTree tree(ranks.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(tree.query(ranks[nums[i]] - 1));
            tree.update(ranks[nums[i]], 1);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};


/********************************************************
 * BST: Binary Search Tree
 * original:[5, 2, 6, 1]
 * reverse: [1, 6, 2, 5]
********************************************************/
struct BSTNode {
    int val;
    int count;
    int left_count;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val): val(val), count(1), left_count(0), left{nullptr}, right{nullptr} {
        
    }
    ~BSTNode() {
        delete left;
        delete right;
    }
    int less_or_equal() const { return count + left_count; }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        std::reverse(nums.begin(), nums.end());
        std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
        vector<int> res{0};
        for (int i = 1; i < nums.size(); i++) {
            res.push_back(insert(root.get(), nums[i]));
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    
private:
    int insert(BSTNode* root, int val) {
        if (root->val == val) {
            ++root->count;
            return root->left_count;
        } else if (val < root->val) {
            ++root->left_count;
            if (root->left == nullptr) {
                root->left = new BSTNode(val);
                return 0;
            }
            return insert(root->left, val);
        } else {
            if (root->right == nullptr) {
                root->right = new BSTNode(val);
                return root->less_or_equal();
            }
            return root->less_or_equal() + insert(root->right, val);
        }
    }
};
