#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rabbits-in-forest/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        res = 0
        m = collections.defaultdict(int)
        for ans in answers:
            m[ans] += 1
        for k, v in m.items():
            res += (v + k) // (k + 1) * (k + 1)
        return res
