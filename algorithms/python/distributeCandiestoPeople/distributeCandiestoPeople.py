#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distribute-candies-to-people/
# Author: Miao Zhang
# Date:   2021-04-09

class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        p = int((2 * candies + 0.25) ** 0.5 - 0.5)
        remaining = int(candies - (p + 1) * p * 0.5)
        rows, cols = p // num_people, p % num_people

        res = [0] * num_people
        for i in range(num_people):
            res[i] = (i + 1) * rows + int(rows * (rows - 1) * 0.5) * num_people
            if i < cols:
                res[i] += i + 1 + rows * num_people
        res[cols] += remaining
        return res
