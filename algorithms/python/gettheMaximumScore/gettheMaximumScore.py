#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/get-the-maximum-score/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        kMod = 1e9 + 7
        n1 = len(nums1)
        n2 = len(nums2)
        dp1 = [0] * (n1 + 1)
        dp2 = [0] * (n2 + 1)
        i = 0
        j = 0
        while i < n1 or j < n2:
            if i < n1 and j < n2 and nums1[i] == nums2[j]:
                dp1[i + 1] = dp2[j + 1] = max(dp1[i], dp2[j]) + nums1[i]
                i += 1
                j += 1
            elif i < n1 and (j == n2 or nums1[i] < nums2[j]):
                dp1[i + 1] = dp1[i] + nums1[i]
                i += 1
            elif j < n2 and (i == n1 or nums2[j] < nums1[i]):
                dp2[j + 1] = dp2[j] + nums2[j]
                j += 1
        return int(max(dp1[-1], dp2[-1]) % kMod)
