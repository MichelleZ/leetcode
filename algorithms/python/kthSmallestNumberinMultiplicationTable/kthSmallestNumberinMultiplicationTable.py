#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
# Author: Miao Zhang
# Date:   2021-02-27

class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        l = 1
        r = m * n + 1
        while l < r:
            mid = l + (r - l) // 2
            if self.counter(m, n, mid) >= k:
                r = mid
            else:
                l = mid + 1
        return l

    def counter(self, m: int, n: int, mid: int) -> int:
        cnt = 0
        for i in range(1, m + 1):
            cnt += min(n, mid // i)
        return cnt
