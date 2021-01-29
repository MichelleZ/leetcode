#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/add-digits/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0: return 0
        else:
            return (num - 1) % 9 + 1
