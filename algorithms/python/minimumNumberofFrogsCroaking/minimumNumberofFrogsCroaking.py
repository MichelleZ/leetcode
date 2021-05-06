#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        idx = {v: i for i, v in enumerate('croak')}
        cnt = [0] * 5
        cur = 0
        res = 0
        for c in croakOfFrogs:
            i = idx[c]
            cnt[i] += 1
            if c == 'c':
                cur += 1
                res = max(res, cur)
                continue
            if cnt[i] > cnt[i - 1]: return -1
            if c == 'k':
                cur -= 1
        return -1 if cur else res
