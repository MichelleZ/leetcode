#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        minlens = [float('inf')] * n
        l = 0
        res = float('inf')
        sums = 0
        minlen = float('inf')
        for r in range(n):
            sums += arr[r]
            while sums > target:
                sums -= arr[l]
                l += 1
            if sums == target:
                curlen = r - l + 1
                if l > 0 and minlens[l - 1] != float('inf'):
                    res = min(res, curlen + minlens[l - 1])
                minlen = min(minlen, curlen)
            minlens[r] = minlen
        return -1 if res == float('inf') else res
                
