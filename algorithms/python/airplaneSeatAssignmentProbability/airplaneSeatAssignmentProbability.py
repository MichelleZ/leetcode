#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/airplane-seat-assignment-probability/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        if n == 1:
            return 1.0
        else:
            return 0.5
