#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-longest-awesome-substring/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def longestAwesome(self, s: str) -> int:
        idx = [len(s)] * 1024
        idx[0] = -1
        res = 0
        mask = 0
        for i, c in enumerate(s):
            mask ^= 1 << (ord(c) - ord('0'))
            res = max(res, i - idx[mask])
            for j in range(10):
                res = max(res, i - idx[mask ^ (1 << j)])
            idx[mask] = min(idx[mask], i)
        return res
