#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/increasing-decreasing-string/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def sortString(self, s: str) -> str:
        chars = string.ascii_lowercase + string.ascii_lowercase[::-1]
        cnt = collections.Counter(s)
        res = ''
        while len(res) != len(s):
            for c in chars:
                if cnt[c] > 0:
                    cnt[c] -= 1
                    res += c
        return res
