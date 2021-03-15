#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/goat-latin/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def toGoatLatin(self, S: str) -> str:
        res = ''
        idx = 1
        for i, w in enumerate(S.split()):
            if w[0] not in 'aeiouAEIOU':
                w = w[1:] + w[0]
            res += ' ' + w + 'ma' + 'a' * idx
            idx += 1
        return res[1:]
