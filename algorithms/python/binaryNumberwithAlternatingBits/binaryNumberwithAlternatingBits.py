#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-number-with-alternating-bits/
# Author: Miao Zhang
# Date:   2021-03-02

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        return '00' not in bin(n) and '11' not in bin(n)
