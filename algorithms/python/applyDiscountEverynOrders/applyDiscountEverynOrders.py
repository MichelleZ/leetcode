#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/apply-discount-every-n-orders/
# Author: Miao Zhang
# Date:   2021-04-26

class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n = n
        self.discount = discount
        self.customerid = 0
        self.prices = collections.defaultdict(int)
        for i in range(len(products)):
            self.prices[products[i]] = prices[i]

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.customerid += 1
        res = 0
        for i in range(len(product)):
            res += self.prices[product[i]] * amount[i]
        if self.customerid % self.n == 0:
            res -= res * self.discount / 100
        return res


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
