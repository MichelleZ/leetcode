#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        res = 0
        sums = 0
        for i in range(len(arr)):
            sums += arr[i]
            if i >= k - 1:
                if sums >= threshold * k:
                    res += 1
                sums -= arr[i - k + 1]
        return res
