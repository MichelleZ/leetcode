#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-product-of-word-lengths/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        from collections import defaultdict
        dic = defaultdict(int)
        res = 0
        for i in range(len(words)):
            w = words[i]
            for c in w:
                dic[w] |= 1 << (ord(c) - ord('a'))
            for j in range(i):
                if not dic[words[i]] & dic[words[j]]:
                    res = max(res, len(words[i]) * len(words[j]))
        return res
