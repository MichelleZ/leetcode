#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/increasing-order-search-tree/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = TreeNode(0)
        self.prev = dummy
        
        def inorder(root):
            if not root: return
            inorder(root.left)
            self.prev.right = root
            self.prev = root
            root.left = None
            inorder(root.right)
        
        inorder(root)
        return dummy.right
