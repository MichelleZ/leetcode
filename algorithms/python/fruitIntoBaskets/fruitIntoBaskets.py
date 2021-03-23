#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fruit-into-baskets/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        l = 0
        res = 0
        cnt = collections.Counter()
        for r, tye in enumerate(tree):
            cnt[tye] += 1
            while len(cnt) > 2:
                cnt[tree[l]] -= 1
                if cnt[tree[l]] == 0:
                    del cnt[tree[l]]
                l += 1
            res = max(res, r - l + 1)
        return res
