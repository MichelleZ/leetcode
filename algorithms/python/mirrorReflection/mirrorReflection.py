#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/mirror-reflection/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        n = p
        a = q
        while n % 2 == 0 and a % 2 == 0:
            n, a = n / 2, a / 2
        if n % 2 == 0 and a % 2 == 1:
            return 2
        elif n % 2 == 1 and a % 2 == 1:
            return 1
        elif n % 2 == 1 and a % 2 == 0:
            return 0
