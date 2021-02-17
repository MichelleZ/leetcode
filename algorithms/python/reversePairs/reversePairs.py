#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-pairs/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        return self.mergeSort(nums, 0, len(nums) - 1)
    
    def mergeSort(self, nums: List[int], left: int, right: int) -> int:
        if left >= right: return 0
        mid = left + (right - left) // 2
        res = self.mergeSort(nums, left, mid) + self.mergeSort(nums, mid + 1, right)
        i = left
        j = mid + 1
        while i <= mid and j <= right:
            if nums[i] / 2.0 > nums[j]:
                res += mid - i + 1
                j += 1
            else:
                i += 1
        
        # merge array
        l1 = nums[left: mid + 1]
        l2 = nums[mid + 1: right + 1]
        idx = left
        p1 = 0
        p2 = 0
        while p1 < len(l1) and p2 < len(l2):
            if l1[p1] < l2[p2]:
                nums[idx] = l1[p1]
                p1 += 1
            else:
                nums[idx] = l2[p2]
                p2 += 1
            idx += 1
        while p1 < len(l1):
            nums[idx] = l1[p1]
            idx += 1
            p1 += 1
        while p2 < len(l2):
            nums[idx] = l2[p2]
            idx += 1
            p2 += 1
        return res
