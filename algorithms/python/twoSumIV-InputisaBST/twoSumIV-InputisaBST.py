#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
# Author: Miao Zhang
# Date:   2021-02-26

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        nums = []
        self.inorder(root, nums)
        l = 0
        r = len(nums) - 1
        while l < r:
            sums = nums[l] + nums[r]
            if sums == k: 
                return True
            elif sums > k:
                r -= 1
            else:
                l += 1
        return False
    
    def inorder(self, root: TreeNode, nums: List[int]) -> None:
        if not root: return
        self.inorder(root.left, nums)
        nums.append(root.val)
        self.inorder(root.right, nums)
