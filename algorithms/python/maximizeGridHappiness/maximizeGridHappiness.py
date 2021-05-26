#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximize-grid-happiness/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        init, gain = [None, 120, 40], [None, -30, 20]

        def get(val, i):
            return (val // (3 ** i)) % 3
        def update(val, s):
            return (val * 3 + s) % (3 ** n)

        @lru_cache(None)
        def dp(x: int, y: int, i: int, e: int, mask: int) -> int:
            if y == n: x, y = x + 1, 0
            if i + e == 0 or x == m: return 0
            res = dp(x, y + 1, i, e, update(mask, 0))
            up, left = get(mask, n - 1), get(mask, 0)
            for cur, cnt in enumerate([i, e], 1):
                if cnt == 0: continue
                s = init[cur]
                if y - 1 >= 0 and left:
                    s += gain[cur] + gain[left]
                if x - 1 >= 0 and up:
                    s += gain[cur] + gain[up]
                res = max(res, s + dp(x, y + 1, i - (cur == 1),
                                     e - (cur == 2),
                                     update(mask, cur)))
            return res

        return dp(0, 0, introvertsCount, extrovertsCount, 0)
