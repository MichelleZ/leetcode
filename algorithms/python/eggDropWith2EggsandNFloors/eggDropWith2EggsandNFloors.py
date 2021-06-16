#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def twoEggDrop(self, n: int) -> int:
        return ceil((-1 + sqrt(n * 8 + 1)) / 2)
