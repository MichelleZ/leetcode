#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/counting-bits/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]
        while len(res) <= num:
            tmp = [i + 1 for i in res]
            res += tmp
        return res[:num + 1]
