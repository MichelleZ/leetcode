#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distance-between-bus-stops/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        if start > destination:
            start, destination = destination, start
        sums = sum(distance)
        d1 = sum(distance[start: destination])
        return min(d1, sums - d1)
