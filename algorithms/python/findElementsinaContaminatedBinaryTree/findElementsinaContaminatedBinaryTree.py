#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-20

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: TreeNode):
        self.tree = set()

        def recover(root, val):
            if not root: return
            root.val = val
            self.tree.add(val)
            recover(root.left, 2 * val + 1)
            recover(root.right, 2 * val + 2)

        recover(root, 0)

    def find(self, target: int) -> bool:
        return target in self.tree


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
