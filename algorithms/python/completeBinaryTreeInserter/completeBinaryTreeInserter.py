#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/complete-binary-tree-inserter/
# Author: Miao Zhang
# Date:   2021-03-24

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:

    def __init__(self, root: TreeNode):
        self.q = collections.deque()
        self.q.append(root)
        self.root = root
        

    def insert(self, v: int) -> int:
        while self.q:
            node = self.q[0]
            if node.left and node.right:
                self.q.append(node.left)
                self.q.append(node.right)
                self.q.popleft()
            elif node.left:
                node.right = TreeNode(v)
                return node.val
            else:
                node.left = TreeNode(v)
                return node.val
            

    def get_root(self) -> TreeNode:
        return self.root


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
