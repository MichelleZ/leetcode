#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reaching-points/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx >= sx and ty >= sy:
            if tx > ty:
                if ty == sy: return (tx - sx) % ty == 0
                tx %= ty
            else:
                if tx == sx: return (ty - sy) % tx == 0
                ty %= tx
        return tx == sx and ty == sy
