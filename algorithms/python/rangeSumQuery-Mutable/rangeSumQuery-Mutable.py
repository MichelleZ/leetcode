#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/range-sum-query-mutable/
# Author: Miao Zhang
# Date:   2021-02-01

class BinaryIndexTree:
    def __init__(self, n):
        self._sums = [0 for _ in range(n + 1)]
    
    def update(self, i, delta):
        while i < len(self._sums):
            self._sums[i] += delta
            i += i & (-i)
    
    def query(self, i):
        res = 0
        while i > 0:
            res += self._sums[i]
            i -= i & (-i)
        return res

    
class NumArray:

    def __init__(self, nums: List[int]):
        self._nums = nums;
        self._tree = BinaryIndexTree(len(nums))
        for i in range(len(nums)):
            self._tree.update(i + 1, nums[i])

    def update(self, index: int, val: int) -> None:
        self._tree.update(index + 1, val - self._nums[index])
        self._nums[index] = val
        
    def sumRange(self, left: int, right: int) -> int:
        return self._tree.query(right + 1) - self._tree.query(left)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)

##########################################################################################
#Segment Tree

class SegmentTreeNode:
    def __init__(self, start, end, sum, left = None, right = None):
        self.start = start
        self.end = end
        self.sum = sum
        self.left = left
        self.right = right

class SegmentTree:
    def __init__(self, start, end, nums):
        self._root = self._buildTree(start, end, nums)
    
    def _buildTree(self, start, end, nums):
        if start == end:
            return SegmentTreeNode(start, end, nums[start])
        mid = start + (end - start) / 2;
        left = self._buildTree(start, mid, nums)
        right = self._buildTree(mid + 1, end, nums)
        return SegmentTreeNode(start, end, left.sum + right.sum, left, right)
    
    def update(self, i, val):
        self._update(self._root, i, val)
    
    def _update(self, root, i, val):
        if root.start == i and root.end == i:
            root.sum = val
            return
        mid = root.start + (root.end - root.start) // 2
        if i <= mid:
            self._update(root.left, i, val)
        else:
            self._update(root.right, i, val)
        root.sum = root.left.sum + root.right.sum
    
    def sumRange(self, left, right):
        return self._sumRange(self._root, left, right)
    
    def _sumRange(self, root, left, right):
        if root.start == left and root.end == right:
            return root.sum
        mid = root.start + (root.end - root.start) // 2
        if right <= mid:
            return self._sumRange(root.left, left, right)
        elif left > mid:
            return self._sumRange(root.right, left, right)
        else:
            return self._sumRange(root.left, left, mid) + self._sumRange(root.right, mid + 1, right)
         
    
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self._nums = nums
        self._tree = SegmentTree(0, len(nums) - 1, nums)

    def update(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        self._tree.update(index, val)

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return self._tree.sumRange(left, right)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
