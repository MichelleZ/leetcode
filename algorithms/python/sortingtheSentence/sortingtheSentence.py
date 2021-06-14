#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sorting-the-sentence/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def sortSentence(self, s: str) -> str:
        slist = s.split()
        slist.sort(key=lambda x: x[-1])
        res = ''
        for c in slist:
            res += c[:-1] + ' '
        return res[: -1]
