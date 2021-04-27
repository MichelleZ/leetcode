#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/linked-list-in-binary-tree/
# Author: Miao Zhang
# Date:   2021-04-27

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if not root: return False
        return self.isPath(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
    
    def isPath(self, head: ListNode, root: TreeNode) -> bool:
        if not head: return True
        if not root: return False
        if head.val != root.val: return False
        return self.isPath(head.next, root.left) or self.isPath(head.next, root.right)
