#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/beautiful-array/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def beautifulArray(self, N: int) -> List[int]:
        res = [1]
        while len(res) < N:
            res = [2 * i - 1 for i in res] + [2 * i for i in res]
        return [i for i in res if i <= N]
