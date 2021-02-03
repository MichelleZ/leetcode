#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/intersection-of-two-arrays/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1, s2 = set(nums1), set(nums2)
        return list(s1.intersection(s2))
