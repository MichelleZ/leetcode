#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/asteroid-collision/
# Author: Miao Zhang
# Date:   2021-03-05

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []
        for a in asteroids:
            while res and a < 0 < res[-1]:
                if res[-1] < -a:
                    res.pop()
                    continue
                elif res[-1] == -a:
                    res.pop()
                break
            else:
                res.append(a)
        return res
