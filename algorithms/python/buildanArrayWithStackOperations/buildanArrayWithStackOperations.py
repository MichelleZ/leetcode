#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/build-an-array-with-stack-operations/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        i = 1
        for num in target:
            while i != num:
                res.append('Push')
                res.append('Pop')
                i += 1
            res.append('Push')
            i += 1
        return res
