#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def countOrders(self, n: int) -> int:
        kMod = 10 ** 9 + 7
        res = 1
        for i in range(2, n + 1):
            res = res * i * (2 * i -1) % kMod
        return res
