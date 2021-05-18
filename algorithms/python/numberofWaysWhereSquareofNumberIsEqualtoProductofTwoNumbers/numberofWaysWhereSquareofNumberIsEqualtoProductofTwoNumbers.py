#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        x = self.solve(nums1, nums2)
        y = self.solve(nums2, nums1)
        return x + y

    def solve(self, nums1: List[int], nums2: List[int]):
        res = 0
        cnt = {}
        for n2 in nums2:
            if n2 not in cnt:
                cnt[n2] = 1
            else:
                cnt[n2] += 1
        for n1 in nums1:
            for n2 in cnt:
                r = n1 * n1 // n2
                if n1 * n1 % n2 or r not in cnt:
                    continue
                if r == n2:
                    res += cnt[n2] * (cnt[n2] - 1)
                else:
                    res += cnt[n2] * cnt[r]
        return res // 2
