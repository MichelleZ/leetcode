#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/serialize-and-deserialize-bst/
# Author: Miao Zhang
# Date:   2021-02-12

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        res = []
        
        def pre_order(root: TreeNode):
            if root:
                res.append(str(root.val))
                pre_order(root.left)
                pre_order(root.right)
        pre_order(root)
        return ' '.join(res)

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        from collections import deque
        q = deque([int(d) for d in data.split()])
        
        def build(minVal: int, maxVal: int) -> TreeNode:
            while q and minVal < q[0] < maxVal:
                val = q.popleft()
                root = TreeNode(val)
                root.left = build(minVal, val)
                root.right = build(val, maxVal)
                return root
        
        return build(float('-inf'), float('inf'))
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
