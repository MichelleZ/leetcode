#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-smallest-instructions/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination
        res = list()
        for i in range(v + h):
            if h > 0:
                tmp = math.comb(h + v - 1, h - 1)
                if k > tmp:
                    res.append('V')
                    v -= 1
                    k -= tmp
                else:
                    res.append('H')
                    h -= 1
            else:
                res.append('V')
                v -= 1
        return ''.join(res)
