#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-split-a-string/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def numWays(self, s: str) -> int:
        kMod = 10 ** 9 + 7
        n = len(s)
        cnt = collections.defaultdict(int)
        c = 0
        for ch in s:
            if ch == '1':
                c += 1
            cnt[c] += 1
        if c % 3 != 0:
            return 0
        if c == 0:
            return ((n - 1) * (n - 2) // 2) % kMod
        return (cnt[c // 3] * cnt[c // 3 * 2]) % kMod
