#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        cnt = collections.Counter(arr)
        freq = cnt.most_common()[::-1]
        res = len(freq)
        for _, v in freq:
            if k >= v:
                res -= 1
                k -= v
            else:
                break
        return res
