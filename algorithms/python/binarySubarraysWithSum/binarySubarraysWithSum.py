#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-subarrays-with-sum/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        count = [0 for _ in range(len(A) + 1)]
        count[0] = 1
        res = 0
        sums = 0
        for a in A:
            sums += a
            if sums >= S: res += count[sums - S]
            count[sums] += 1
        return res
