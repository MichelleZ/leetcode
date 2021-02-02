#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/create-maximum-number/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        res = []
        n1 = len(nums1)
        n2 = len(nums2)
        for k1 in range(k + 1):
            k2 = k - k1
            if k1 > n1 or k2 > n2: 
                continue  
            res = max(res, self.merge(self.maxNum(nums1, k1), 
                                      self.maxNum(nums2, k2)))
        return res
    
    def maxNum(self, nums: List[int], k: int) -> List[int]:
        res = []
        if k == 0: return res
        to_pop = len(nums) - k
        for num in nums:
            while res and res[-1] < num and to_pop > 0:
                res.pop()
                to_pop -= 1
            res.append(num)
        return res[:k]
    
    def merge(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        while nums1 or nums2:
            if nums1 > nums2:
                res.append(nums1[0])
                nums1 = nums1[1:]
            else:
                res.append(nums2[0])
                nums2 = nums2[1:]
        return res
