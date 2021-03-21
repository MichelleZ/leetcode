#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/uncommon-words-from-two-sentences/
# Author: Miao Zhang
# Date:   2021-03-21

class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        a = A.split(' ')
        b = B.split(' ')
        cnt = collections.Counter(a + b)
        res = []
        for k, v in cnt.items():
            if v == 1:
                res.append(k)
        return res
