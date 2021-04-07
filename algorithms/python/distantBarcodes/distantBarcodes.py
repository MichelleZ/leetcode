#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distant-barcodes/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        n = len(barcodes)
        pos = 0
        cnt = collections.Counter(barcodes)
        tmp = []
        for k, v in cnt.items():
            tmp.append([v, k])
        tmp.sort(reverse=True)
        res = [0] * n
        for t in tmp:
            for i in range(t[0]):
                if pos >= n: pos = 1
                res[pos] = t[1]
                pos += 2
        return res
