#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/average-waiting-time/
# Author: Miao Zhang
# Date:   2021-05-29

class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        start = 0
        sums = 0
        for c in customers:
            if c[0] > start: start = c[0]
            start += c[1]
            sums += start - c[0]
        return sums / len(customers)
