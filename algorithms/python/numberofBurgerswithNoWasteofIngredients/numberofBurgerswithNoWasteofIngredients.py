#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        x = tomatoSlices // 2 - cheeseSlices
        y = cheeseSlices - x
        if 4 * x + 2 * y == tomatoSlices and x >= 0 and y >= 0:
            return [x, y]
        return []
