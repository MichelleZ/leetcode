#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
# Author: Miao Zhang
# Date:   2021-01-31

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        def dfs(node):
            if not node:
                res.append('null')
                return 
            res.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
    
        dfs(root)
        return ','.join(res)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def dfs(queue):
            val = queue.pop(0)
            if val == 'null':
                return None
            node = TreeNode(val)
            node.left = dfs(queue)
            node.right = dfs(queue)
            return node

        q = data.split(',')
        return dfs(q)
