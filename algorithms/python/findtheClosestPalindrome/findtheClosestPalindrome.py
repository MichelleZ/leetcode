#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-closest-palindrome/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def nearestPalindromic(self, n: str) -> str:
        lenn = len(n)
        num = int(n)
        res = float('inf')
        mindiff = float('inf')
        resset = set()
        resset.add(pow(10, lenn) + 1)
        resset.add(pow(10, lenn - 1) - 1)
        leftpart = int(n[0: (lenn + 1) // 2])
        for i in range(-1, 2):
            pre = str(leftpart + i)
            ss = pre + pre[::-1][(lenn&1):]
            resset.add(int(ss))
        resset.discard(num)
        for r in resset:
            diff = abs(r - num)
            if diff < mindiff:
                mindiff = diff
                res = r
            elif diff == mindiff:
                res = min(res, r)
        return str(res)
