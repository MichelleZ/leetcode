#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-multiple-of-three/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        cnt = [0 for _ in range(10)]
        for d in digits: cnt[d] += 1
        
        def getNum(ds):
            for d in ds: cnt[d] -= 1
            res = ''
            for d in range(9, 0, -1):
                res += str(d) * cnt[d]
            res += (min(1, cnt[0]) if res == '' else cnt[0]) * '0'
            return res
        
        remainders = [[0, 3, 6, 9], [1, 4, 7], [2, 5, 8]]
        r = sum(digits) % 3
        if r == 0: return getNum([])
        for d in remainders[r]:
            if cnt[d]:
                return getNum([d])
        for d1, d2 in zip(remainders[3 - r], remainders[3 - r]):
            if (d1 == d2 and cnt[d1] > 1) or (d1 != d2 and cnt[d1] and cnt[d2]):
                return getNum([d1, d2])
        return ''
