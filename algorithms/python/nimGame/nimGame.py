#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/nim-game/
# Author: Miao Zhang
# Date:   2021-01-31

class Solution:
    def canWinNim(self, n: int) -> bool:
        if n % 4 == 0: return False
        return True
