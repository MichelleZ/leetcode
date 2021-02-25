#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shopping-offers/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        res = sum(p * n for p, n in zip(price, needs))
        for sp in special:
            if all(sp[i] <= needs[i] for i in range(len(needs))):
                remain = [needs[i] - sp[i] for i in range(len(needs))]
                if min(remain) >= 0:
                    res = min(res, sp[-1] + self.shoppingOffers(price, special, remain))
        return res
