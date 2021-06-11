#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/seat-reservation-manager/
# Author: Miao Zhang
# Date:   2021-06-11

from sortedcontainers import SortedSet

class SeatManager:

    def __init__(self, n: int):
        self.sm = SortedSet()
        for i in range(1, n + 1):
            self.sm.add(i)

    def reserve(self) -> int:
        res = self.sm.pop(0)
        return res

    def unreserve(self, seatNumber: int) -> None:
        self.sm.add(seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
