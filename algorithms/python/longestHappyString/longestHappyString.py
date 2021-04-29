#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-happy-string/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        total = a + b + c
        cnt = [a, b, c]
        used = [0, 0, 0]
        res = ''
        for _ in range(total):
            for i in range(3):
                j = (i + 1) % 3
                k = (i + 2) % 3
                if (cnt[i] >= cnt[j] and cnt[i] >= cnt[k] and used[i] != 2) or (cnt[i] > 0 and (used[j] == 2 or used[k] == 2)):
                    res += chr(ord('a') + i)
                    used[i] += 1
                    cnt[i] -= 1
                    used[j] = 0
                    used[k] = 0
                    break
        return res
