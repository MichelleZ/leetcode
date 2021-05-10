#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        l = min(bloomDay)
        r = max(bloomDay) + 1
        tmp = max(bloomDay) + 1
        print(l, r)

        def getBouquets(x):
            cur = 0
            res = 0
            for b in bloomDay:
                if b > x:
                    cur = 0
                    continue
                cur += 1
                if cur == k:
                    cur = 0
                    res += 1
            return res

        while l < r:
            mid = l + (r - l) // 2
            if getBouquets(mid) >= m:
                r = mid
            else:
                l = mid + 1
        return -1 if l >= tmp else l
