#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/k-th-smallest-prime-fraction/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        l = 0.0
        r = 1.0
        while l < r:
            m = (l + r) / 2
            max_f = 0.0
            total = 0
            j = 1
            for i in range(n - 1):
                while j < n and arr[i] > m * arr[j]: j += 1
                if j == n: break
                total += (n - j)
                f = arr[i] / arr[j]
                if f > max_f:
                    x, y, max_f = i, j, f
            if total == k:
                return [arr[x], arr[y]]
            elif total > k:
                r = m
            else:
                l = m
        return []
