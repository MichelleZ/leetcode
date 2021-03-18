#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/exam-room/
# Author: Miao Zhang
# Date:   2021-03-18

class ExamRoom:

    def __init__(self, N: int):
        self.N = N
        self.seats = []

    def seat(self) -> int:
        if not self.seats:
            res = 0
        else:
            dist, res = self.seats[0], 0
            for i, s in enumerate(self.seats):
                if i:
                    prev = self.seats[i - 1]
                    d = (s - prev) // 2
                    if d > dist:
                        dist, res = d, prev + d
            d = self.N - 1 - self.seats[-1]
            if d > dist:
                res = self.N - 1
        
        bisect.insort(self.seats, res)
        return res

    def leave(self, p: int) -> None:
        if p in self.seats:
            self.seats.remove(p)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)
