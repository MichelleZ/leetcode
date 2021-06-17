#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        target = '01'
        cnt = 0
        for i in range(n):
            cnt += (s[i] != target[i % 2])
        res = min(cnt, n - cnt)
        for i in range(n):
            cnt -= (s[i] != target[i % 2])
            cnt += (s[i] != target[(i + n) % 2])
            res = min(res, cnt, n - cnt)
        return res
