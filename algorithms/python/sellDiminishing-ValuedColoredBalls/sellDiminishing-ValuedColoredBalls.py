#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        kMod = 10 ** 9 + 7
        n = len(inventory)
        inventory.sort(reverse=True)
        cur = inventory[0]
        res = 0
        c = 0
        while orders:
            while c < n and inventory[c] == cur: c += 1
            nxt = 0 if c == n else inventory[c]
            cnt = min(orders, c * (cur - nxt))
            t = cur - nxt
            r = 0
            if orders < c * t:
                t = orders // c
                r = orders % c
            nxtp = cur - t
            res = (res + (cur + nxtp + 1) * t // 2 * c + nxtp * r) % kMod
            orders -= cnt
            cur = nxt
        return res
