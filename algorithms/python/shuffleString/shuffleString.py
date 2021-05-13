#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shuffle-string/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        res = [None] * len(s)
        for i in range(len(s)):
            res[indices[i]] = s[i]
        return ''.join(res)
