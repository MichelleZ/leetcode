#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/prison-cells-after-n-days/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:

        def nextDay(cells):
            return [int(i > 0 and i < 7 and cells[i - 1] == cells[i + 1])
                    for i in range(8)]

        seen = {}
        while n > 0:
            c = tuple(cells)
            if c in seen:
                n %= seen[c] - n
            seen[c] = n

            if n >= 1:
                n -= 1
                cells = nextDay(cells)
        return cells
