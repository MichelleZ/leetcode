#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
# Author: Miao Zhang
# Date:   2021-04-13

class Solution:
    def maxRepOpt1(self, text: str) -> int:
        # 'aaabaaa' -> [[a , 3], [b, 1], [a, 3]
        tmp = [[c, len(list(g))] for c, g in itertools.groupby(text)]
        # 'aaabaaa' -> {a: 6, b: 1}
        cnt = collections.Counter(text)
        # only extend 1 more, use min here to avoid the case that there's no extra char to extend
        res = max(min(k + 1, cnt[c]) for c, k in tmp)
        # merge 2 groups together
        for i in range(1, len(tmp) - 1):
            if tmp[i - 1][0] == tmp[i + 1][0] and tmp[i][1] == 1:
                res = max(res, min(tmp[i - 1][1] + tmp[i + 1][1] + 1, cnt[tmp[i + 1][0]]))
        return res
