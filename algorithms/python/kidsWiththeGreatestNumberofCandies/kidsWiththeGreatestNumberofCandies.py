#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxval = max(candies)
        res = [False] * len(candies)
        for i in range(len(candies)):
            res[i] = (candies[i] + extraCandies) >= maxval
        return res
