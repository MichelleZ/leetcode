#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        cnt = collections.defaultdict(int)
        cnt['a'] = 1
        cnt['e'] = 1
        cnt['i'] = 1
        cnt['o'] = 1
        cnt['u'] = 1
        cur = 0
        res = 0
        for r in range(len(s)):
            if r >= k:
                cur -= cnt[s[r - k]]
            cur += cnt[s[r]]
            res = max(res, cur)
        return res
