#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/slowest-key/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        n = len(releaseTimes)
        c = ' '
        maxtime = 0
        for i in range(n):
            k = keysPressed[i]
            time = releaseTimes[i] - (releaseTimes[i - 1] if i > 0 else 0)
            if time > maxtime or (time == maxtime and k > c):
                maxtime = time
                c = k
        return c
