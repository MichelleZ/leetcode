#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/grumpy-bookstore-owner/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        base = 0
        window = 0
        best_window = 0
        for i in range(len(grumpy)):
            if grumpy[i]:
                window += customers[i]
            else:
                base += customers[i]
            if i >= X and grumpy[i - X]:
                window -= customers[i - X]
            best_window = max(best_window, window)
        return base + best_window
