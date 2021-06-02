#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        ball = collections.Counter()
        res = 0
        for i in range(lowLimit, highLimit + 1):
            sums = sum(int(x) for x in str(i))
            ball[sums] += 1
        return ball.most_common()[0][1]
