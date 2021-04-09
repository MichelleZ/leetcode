#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/corporate-flight-bookings/
# Author: Miao Zhang
# Date:   2021-04-09

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        res = [0] * (n + 1)
        for s, e, c in bookings:
            res[s - 1] += c
            res[e] -= c
        for i in range(1, n + 1):
            res[i] += res[i - 1]
        return res[:-1]
