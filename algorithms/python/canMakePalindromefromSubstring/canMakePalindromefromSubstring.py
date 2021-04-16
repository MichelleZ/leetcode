#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/can-make-palindrome-from-substring/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        cnt = [[0] * 26]
        for i, c in enumerate(s):
            cnt.append(cnt[i][:])
            cnt[i + 1][ord(c) - ord('a')] += 1
        res = []
        for l, r, k in queries:
            res.append(sum((cnt[r+1][idx] - cnt[l][idx])&1 for idx in range(26)) // 2 <= k)
        return res
