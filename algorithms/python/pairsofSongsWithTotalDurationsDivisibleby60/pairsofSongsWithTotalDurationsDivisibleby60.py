#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        cnt = [0] * 60
        res = 0
        for t in time:
            t %= 60
            res += cnt[(60 - t) % 60]
            cnt[t] += 1
        return res
