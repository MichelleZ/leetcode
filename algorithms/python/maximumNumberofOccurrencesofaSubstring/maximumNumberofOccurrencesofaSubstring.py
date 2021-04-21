#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        cnt = collections.defaultdict(int)
        res = 0
        n = len(s)
        for i in range(n - minSize + 1):
            cur = s[i: i + minSize]
            if len(set(cur)) <= maxLetters:
                cnt[cur] += 1
                res = max(res, cnt[cur])
        return res

