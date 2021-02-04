#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/water-and-jug-problem/
# Author: Miao Zhang
# Date:   2021-02-04

class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x == z or y == z or x + y == z: return True
        if x + y < z: return False
        return z % gcd(x, y) == 0
