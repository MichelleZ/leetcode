#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stack = []
        for i in range(len(prices)):
            while stack and prices[stack[-1]] >= prices[i]:
                prices[stack[-1]] -= prices[i]
                stack.pop()
            stack.append(i)
        return prices
