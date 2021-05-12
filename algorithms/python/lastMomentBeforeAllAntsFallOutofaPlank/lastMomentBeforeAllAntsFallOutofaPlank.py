#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        t1 = max(left) if left else 0
        t2 = n - min(right) if right else 0
        return max(t1, t2)
