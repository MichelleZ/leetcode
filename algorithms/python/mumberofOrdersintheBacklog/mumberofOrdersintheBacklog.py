#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-orders-in-the-backlog/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        kMod = 10 ** 9 + 7
        # maxheap
        buys = []
        # minheap
        sells = []
        for p, a, t in orders:
            # sell
            if t:
                while a and buys and -buys[0][0] >= p:
                    buyamount = buys[0][1]
                    if buyamount > a:
                        buys[0][1] -= a
                        a = 0
                    else:
                        heapq.heappop(buys)
                        a -= buyamount
                if a > 0:
                    heapq.heappush(sells, [p, a])
            else:
                while a and sells and sells[0][0] <= p:
                    sellamount = sells[0][1]
                    if sellamount > a:
                        sells[0][1] -= a
                        a = 0
                    else:
                        heapq.heappop(sells)
                        a -= sellamount
                if a > 0:
                    heapq.heappush(buys, [-p, a])
        return sum(a for _, a in buys + sells) % kMod
