#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-array-formation-through-concatenation/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        dic = collections.defaultdict(int)
        for i, v in enumerate(pieces):
            dic[v[0]] = i
        res = []
        for a in arr:
            if a not in dic:
                continue
            res.extend(pieces[dic[a]])
        return res == arr
