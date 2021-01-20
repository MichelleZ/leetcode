#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
# Author: Miao Zhang
# Date:   2021-01-19

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        
        pre = []
        low = float('inf')
        res = 0
        for i in range(len(prices)):
            low = min(low, prices[i])
            res = max(res, prices[i] - low)
            pre.append(res)
        
        high = float('-inf')
        res = 0
        post = []
        total_max = 0
        for i in range(len(prices) - 1, -1, -1):
            high = max(high, prices[i])
            res = max(res, high - prices[i])
            post.append(res)
            total_max = max(total_max, res + pre[i])
        return total_max

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        first_buy: get max profit after the first buy
        first_sell: get max profit after the first sell
        sec_buy: get max profit after the sec buy
        sec_sell: get max profit after the sec sell
        '''
        first_buy, first_sell = -sys.maxsize, 0
        sec_buy, sec_sell = -sys.maxsize, 0
        for p in prices:
            first_buy = max(first_buy, -p)
            first_sell = max(first_sell, first_buy + p)
            sec_buy = max(sec_buy, first_sell - p)
            sec_sell = max(sec_sell, sec_buy + p)
        return sec_sell
