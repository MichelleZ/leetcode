#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def beautySum(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            cnt = collections.Counter()
            for j in range(i, len(s)):
                cnt[s[j]] += 1
                maxf = max(cnt.values())
                minf = min(cnt.values())
                res += (maxf - minf)
        return res

