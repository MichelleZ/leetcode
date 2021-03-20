#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
# Author: Miao Zhang
# Date:   2021-03-20

class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        setA = set(arr)
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                a, b = arr[i], arr[j]
                cnt = 2
                while a + b in setA:
                    a, b = b, a + b
                    cnt += 1
                    res = max(res, cnt)
        return res if res > 2 else 0
