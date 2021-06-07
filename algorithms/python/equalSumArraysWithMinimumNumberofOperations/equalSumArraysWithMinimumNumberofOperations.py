#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        l1 = len(nums1)
        l2 = len(nums2)
        if min(l1, l2) * 6 < max(l1, l2) * 1:
            return -1
        s1 = sum(nums1)
        s2 = sum(nums2)
        if s1 > s2: return self.minOperations(nums2, nums1)
        if s1 == s2: return 0
        nums1.sort()
        nums2.sort(reverse=True)
        res = 0
        i, j = 0, 0
        while s1 < s2:
            d1 = 0 if i == l1 else 6 - nums1[i]
            d2 = 0 if j == l2 else nums2[j] - 1
            if d1 >= d2:
                s1 += d1
                i += 1
            else:
                s2 -= d2
                j += 1
            res += 1
        return res
