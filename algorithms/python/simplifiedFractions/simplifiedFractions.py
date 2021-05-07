#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/simplified-fractions/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        res = []
        for i in range(1, n):
            for j in range(i + 1, n + 1):
                if math.gcd(i, j) == 1:
                    res.append(str(i) + '/' + str(j))
        return res
