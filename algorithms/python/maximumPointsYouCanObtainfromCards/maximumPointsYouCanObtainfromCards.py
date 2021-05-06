#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        cur = sum(cardPoints[0: k])
        res = cur
        for i in range(k):
            cur = cur - cardPoints[k - 1 - i] + cardPoints[n - 1 - i]
            res = max(res, cur)
        return res
