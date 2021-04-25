#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        res = []
        for r in restaurants:
            if (not veganFriendly or (veganFriendly and r[2])) and r[3] <= maxPrice and r[4] <= maxDistance:
                res.append((r[1], r[0]))
        res.sort(reverse=True)
        return [r[1] for r in res]
