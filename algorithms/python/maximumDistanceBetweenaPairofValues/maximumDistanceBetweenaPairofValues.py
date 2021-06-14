#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        res = 0
        j = -1
        for i in range(0, len(nums1)):
            while j + 1 < len(nums2) and nums2[j + 1] >= nums1[i]:
                j += 1
            if j >= i: res = max(res, j - i)
        return res
