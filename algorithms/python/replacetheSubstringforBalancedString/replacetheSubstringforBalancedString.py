#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        if n <= 0 or n % 4 != 0:
            return 0
        m = n // 4
        cnt = collections.Counter(s)
        if cnt['Q'] == m and cnt['W'] == m and cnt['E'] == m and cnt['R'] == m:
            return 0
        res = n
        l = 0
        for r in range(n):
            cnt[s[r]] -= 1
            while l <= r and cnt['Q'] <= m and cnt['W'] <= m and cnt['E'] <= m and cnt['R'] <= m:
                res = min(res, r - l + 1)
                cnt[s[l]] += 1
                l += 1
        return res
